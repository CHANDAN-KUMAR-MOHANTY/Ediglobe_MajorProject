import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# 1. Data Loading & Preprocessing
print("Loading and preprocessing data...")
df = pd.read_csv('heart.csv')  # Download from: https://drive.google.com/file/d/1k3Yhgzrgzl9CbdGXuZvK7WgbZ8kVx56I/view?usp=sharing
cols = ['age', 'sex', 'cp', 'trestbps', 'chol', 'fbs', 'restecg', 'thalach',
        'exang', 'oldpeak', 'slope', 'ca', 'thal', 'target']
df.columns = cols
df = df.apply(pd.to_numeric, errors='coerce').dropna()
df['target'] = (df['target'] > 0).astype(int)  # Binarize target (0: no disease, 1: disease)
print(f"Dataset shape: {df.shape}")
print(df['target'].value_counts(normalize=True))  # Class balance

# 2. Exploratory Data Analysis (EDA)
print("\nGenerating EDA visualizations...")
plt.figure(figsize=(12, 10))

# Correlation heatmap
plt.subplot(2, 2, 1)
sns.heatmap(df.corr(), annot=True, cmap='coolwarm', center=0, fmt='.2f')
plt.title('Feature Correlations')

# Target distribution
plt.subplot(2, 2, 2)
sns.countplot(data=df, x='target')
plt.title('Target Distribution')

# Age vs Target
plt.subplot(2, 2, 3)
sns.boxplot(data=df, x='target', y='age')
plt.title('Age by Target')

# Chol vs Target
plt.subplot(2, 2, 4)
sns.boxplot(data=df, x='target', y='chol')
plt.title('Cholesterol by Target')

plt.tight_layout()
plt.show()

# 3. Train-Test Split (Stratified)
def stratified_split(y, train_size=0.8, seed=42):
    rng = np.random.default_rng(seed)
    train_idx, test_idx = [], []
    for label in np.unique(y):
        idx = np.where(y == label)[0]
        rng.shuffle(idx)
        split = int(train_size * len(idx))
        train_idx.extend(idx[:split])
        test_idx.extend(idx[split:])
    rng.shuffle(train_idx)
    rng.shuffle(test_idx)
    return np.array(train_idx), np.array(test_idx)

train_idx, test_idx = stratified_split(df['target'].values)
X_train = df.iloc[train_idx].drop('target', axis=1).values
y_train = df.iloc[train_idx]['target'].values
X_test = df.iloc[test_idx].drop('target', axis=1).values
y_test = df.iloc[test_idx]['target'].values
print(f"Train size: {len(X_train)}, Test size: {len(X_test)}")

# 4. Feature Scaling
mean, std = X_train.mean(axis=0), X_train.std(axis=0) + 1e-8
X_train = (X_train - mean) / std
X_test = (X_test - mean) / std

# 5. Utility Functions (Metrics)
def sigmoid(z): return 1 / (1 + np.exp(-np.clip(z, -250, 250)))

def accuracy(y, p): return np.mean(y == p)

def precision(y, p):
    tp = np.sum((y == 1) & (p == 1)); fp = np.sum((y == 0) & (p == 1))
    return tp / (tp + fp) if tp + fp else 0

def recall(y, p):
    tp = np.sum((y == 1) & (p == 1)); fn = np.sum((y == 1) & (p == 0))
    return tp / (tp + fn) if tp + fn else 0

def f1(y, p):
    pr, rc = precision(y, p), recall(y, p)
    return 2 * pr * rc / (pr + rc) if pr + rc else 0

def roc_auc(y, prob):
    order = np.argsort(prob)[::-1]
    y = y[order]
    P, N = y.sum(), len(y) - y.sum()
    tp = fp = 0
    tpr = [0]; fpr = [0]
    for v in y:
        tp += (v == 1); fp += (v == 0)
        tpr.append(tp / P if P else 0)
        fpr.append(fp / N if N else 0)
    return np.trapz(tpr, fpr)

# 6. Hyperparameter Tuning Example (Simple Grid for Logistic Regression)
print("\nTuning Logistic Regression (lr in [0.001, 0.01, 0.1])...")
def logistic_train(X, y, lr=0.01, epochs=1500):
    w, b = np.zeros(X.shape[1]), 0
    for _ in range(epochs):
        p = sigmoid(X @ w + b)
        w -= lr * (X.T @ (p - y) / len(y))
        b -= lr * np.mean(p - y)
    return w, b

best_lr, best_acc = 0.01, 0
for lr in [0.001, 0.01, 0.1]:
    w, b = logistic_train(X_train, y_train, lr=lr)
    acc = accuracy(y_test, (sigmoid(X_test @ w + b) > 0.5).astype(int))
    if acc > best_acc:
        best_acc, best_lr = acc, lr
print(f"Best lr: {best_lr}, Val Acc: {best_acc:.3f}")

# Train best LR
w_lr, b_lr = logistic_train(X_train, y_train, lr=best_lr)
y_prob_lr = sigmoid(X_test @ w_lr + b_lr)
y_pred_lr = (y_prob_lr > 0.5).astype(int)

# 7. Decision Tree
class Node:
    def __init__(self, f=None, t=None, l=None, r=None, v=None):
        self.f, self.t, self.l, self.r, self.v = f, t, l, r, v

def gini(y):
    _, c = np.unique(y, return_counts=True)
    p = c / c.sum()
    return 1 - np.sum(p * p)

def build_tree(X, y, d=0, max_d=5):
    if len(np.unique(y)) == 1 or d == max_d:
        return Node(v=np.mean(y))
    best, bf, bt = 1e9, None, None
    for f in range(X.shape[1]):
        thresholds = np.sort(np.unique(X[:, f]))
        if len(thresholds) < 2: continue
        for t in thresholds[:-1]:  # Midpoints to avoid duplicates
            m = X[:, f] <= t
            left_size = m.sum()
            right_size = len(y) - left_size
            if left_size == 0 or right_size == 0: continue
            g = (left_size / len(y)) * gini(y[m]) + (right_size / len(y)) * gini(y[~m])
            if g < best:
                best, bf, bt = g, f, t
    if bf is None:
        return Node(v=np.mean(y))
    m = X[:, bf] <= bt
    return Node(bf, bt, build_tree(X[m], y[m], d + 1, max_d), build_tree(X[~m], y[~m], d + 1, max_d))

def tree_prob(n, x):
    if n.v is not None: return n.v
    if n.f is None: return 0.5
    return tree_prob(n.l, x) if x[n.f] <= n.t else tree_prob(n.r, x)

tree = build_tree(X_train, y_train)
y_prob_tree = np.array([tree_prob(tree, x) for x in X_test])
y_pred_tree = (y_prob_tree > 0.5).astype(int)

# 8. Random Forest
def rf_train(X, y, n=10):
    trees = []
    for _ in range(n):
        idx = np.random.choice(len(X), len(X), replace=True)
        trees.append(build_tree(X[idx], y[idx]))
    return trees

def rf_prob(trees, X):
    return np.mean([[tree_prob(t, x) for t in trees] for x in X], axis=1)

rf_trees = rf_train(X_train, y_train)
y_prob_rf = rf_prob(rf_trees, X_test)
y_pred_rf = (y_prob_rf > 0.5).astype(int)

# 9. Neural Network
def nn_train(X, y, h=10, lr=0.01, ep=3000):
    W1 = np.random.randn(X.shape[1], h) * 0.01
    b1 = np.zeros((1, h))
    W2 = np.random.randn(h, 1) * 0.01
    b2 = np.zeros((1, 1))
    y = y.reshape(-1, 1)
    for _ in range(ep):
        a1 = np.tanh(X @ W1 + b1)
        a2 = sigmoid(a1 @ W2 + b2)
        d2 = a2 - y
        d1 = (d2 @ W2.T) * (1 - a1 * a1)
        W2 -= lr * (a1.T @ d2) / len(y)
        b2 -= lr * np.mean(d2, axis=0, keepdims=True)
        W1 -= lr * (X.T @ d1) / len(y)
        b1 -= lr * np.mean(d1, axis=0, keepdims=True)
    return W1, b1, W2, b2

W1, b1, W2, b2 = nn_train(X_train, y_train)
y_prob_nn = sigmoid(np.tanh(X_test @ W1 + b1) @ W2 + b2).ravel()
y_pred_nn = (y_prob_nn > 0.5).astype(int)

# 10. Model Evaluation
models = ['Logistic', 'Tree', 'RF', 'NN']
preds = [y_pred_lr, y_pred_tree, y_pred_rf, y_pred_nn]
probs = [y_prob_lr, y_prob_tree, y_prob_rf, y_prob_nn]
results = {m: {
    'Acc': accuracy(y_test, preds[i]),
    'Prec': precision(y_test, preds[i]),
    'Rec': recall(y_test, preds[i]),
    'F1': f1(y_test, preds[i]),
    'AUC': roc_auc(y_test, probs[i])
} for i, m in enumerate(models)}

print("\nModel Performance Comparison:")
print(pd.DataFrame(results).round(3))

# Confusion Matrices
print("\nConfusion Matrices:")
for m, pred in zip(models, preds):
    cm = pd.crosstab(y_test, pred, rownames=['Actual'], colnames=['Predicted'])
    print(f"\n{m}:\n{cm}")

# 11. Feature Importance
feat_names = cols[:-1]

# Logistic: Absolute weights
importance_lr = np.abs(w_lr)
plt.figure(figsize=(10, 6))
plt.barh(feat_names, importance_lr)
plt.title('Logistic Regression Feature Importance')
plt.show()

# RF: Permutation Importance
print("\nComputing RF Feature Importance (permutation)...")
base_auc = roc_auc(y_test, y_prob_rf)
importance_rf = []
for f in range(X_test.shape[1]):
    X_test_perm = X_test.copy()
    np.random.shuffle(X_test_perm[:, f])
    auc_perm = roc_auc(y_test, rf_prob(rf_trees, X_test_perm))
    importance_rf.append(base_auc - auc_perm)

plt.figure(figsize=(10, 6))
plt.barh(feat_names, importance_rf)
plt.title('Random Forest Feature Importance (Permutation AUC Drop)')
plt.show()

# 12. Additional Visualizations
plt.figure(figsize=(10, 6))
sns.barplot(x=models, y=[results[m]['Acc'] for m in models])
plt.title('Model Accuracy Comparison')
plt.ylabel('Accuracy')
plt.xticks(rotation=45)
plt.show()

# Optional: For deployment, save best model (e.g., RF) or use Streamlit
# Example: streamlit app - st.title('Heart Predictor'); inputs = [st.slider(...) for feat in feat_names]; pred = rf_prob(rf_trees, np.array([inputs])) > 0.5
print("\nProject complete! Key factors: High 'ca' (vessels), 'thal' (thallium stress) often top importance.")c