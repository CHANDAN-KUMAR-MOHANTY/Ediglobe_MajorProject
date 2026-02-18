#include <stdio.h>
#include <stdlib.h>

// Define a structure for student details
struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    // Declare a pointer to the structure
    struct Student *ptr;

    // Dynamically allocate memory for one student
    ptr = (struct Student *)malloc(sizeof(struct Student));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input student details
    printf("Enter student details:\n");

    // Input the student's name (fgets to allow spaces in name)
    printf("Name: ");
    getchar();  // To consume the newline character left by previous scanf
    fgets(ptr->name, sizeof(ptr->name), stdin);

    // Input the student's age
    printf("Age: ");
    scanf("%d", &ptr->age);

    // Input the student's grade
    printf("Grade: ");
    scanf("%f", &ptr->grade);

    // Output the entered student details
    printf("\nStudent Details:\n");
    printf("Name: %s", ptr->name); // Output the name (fgets includes newline)
    printf("Age: %d\n", ptr->age);
    printf("Grade: %.2f\n", ptr->grade);

    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}
