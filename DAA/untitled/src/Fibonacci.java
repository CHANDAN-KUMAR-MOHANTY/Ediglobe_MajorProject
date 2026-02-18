import java.util.Scanner;

public class Fibonacci {
    static void Fib(int n){
        int f0=0;
        int f1=1;
        if(n>0){
            System.out.print(0+" ");
        }
        if(n>1){
            System.out.print(1+" ");
        }
        if(n>2){
            for(int i=2;i<=n;i++){
                int f2=f1+f0;
                System.out.print(f2+" ");
                f0=f1;
                f1=f2;
            }
        }
    }
    static int recFib(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return recFib(n-1)+recFib(n-2);
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the Number: ");
        int a=s.nextInt();
        Fib(a);

        System.out.println("\nRecursive answer:");
        System.out.println(recFib(a));
    }
}
