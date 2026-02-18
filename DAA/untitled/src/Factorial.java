
import java.util.*;


public class Factorial {
    static int Fact(int n){
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        return fact;
    }
    static int recFact(int n){
        if(n==1){
            return 1;
        }
        return n*recFact(n-1);
    }


    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the Number: ");
        int a=s.nextInt();
        System.out.println(Fact(a));
        System.out.println(recFact(a));

    }
}