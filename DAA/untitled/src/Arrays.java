import java.util.*;

public class Arrays {
    static void linSearch(int a[],int n,int key){
        int found=0;
        for(int i=0;i<n;i++){
            if(a[i]==key){
                System.out.println("The key element "+key+"is found in the array at"+i);
                found=1;
                break;
            }

        }

        return ;
    }
    public static void main(String[] args) {
        Scanner s= new Scanner (System.in);
        System.out.println("Enter value of n:\n");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the no. of elements to the array:\n");
        for(int i=0;i<n;i++){
            a[i]=s.nextInt();
        }
    }
}
