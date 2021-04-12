import java.util.*;
public class fib1
{
    public static void main(String[] args)
    {
        int x ,temp;
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the number");
        x=scn.nextInt(); 
        int m=0;
        int n=1;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<=i;j++)
            {
                System.out.print( m+" ");
                temp=n;
                n=n+m;
                m=temp;


            }
            System.out.println();
        }
        
    }
}