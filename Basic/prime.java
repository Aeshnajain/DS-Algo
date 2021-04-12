import java.util.*;

public class prime
 {
         public static void main(String[] args)
        {
           Scanner scn=new Scanner(System.in);
           System.out.println("enter a number");
           int n;
           n=scn.nextInt();
           for(int i=1;i<=n;i++)
           {
               System.out.println("enter number "+i);
               int x;
               x=scn.nextInt();
               boolean flag=true;
               for(int j=2;j<=x/2;j++)
               {
                   if (x%j==0)
                   {
                       flag=false;
                       break;
                   }
               }
               if (flag==true)
               {
                   System.out.println("prime");

               }
               else
               {
                   System.out.println("composite");
               }
               
           }
        }
    
}

