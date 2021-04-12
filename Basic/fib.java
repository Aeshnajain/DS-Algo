import java.util.*;

public class fib
{
    public static void main (String[] args)
    {
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the number");
        int n;
        n=scn.nextInt();
        int temp;
        int m=1;
        int i=0;
        int y=1;
        System.out.print(i);
        System.out.print(y);
        while(m!=n-1)
        {
           temp=y;
           y=y+i;
           i=temp;
           System.out.print(+y);
           m++; 
        }
    
      
    }
}