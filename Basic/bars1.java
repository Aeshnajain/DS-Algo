import java.util.*;

public class bars1
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the length of the array");
        int n=scn.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<arr.length;i++)
        {
            System.out.print("enter the values of array");
            arr[i]=scn.nextInt();
        }
        int max=arr[0];
        for (int i=1;i<arr.length;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        for(int i=max;i>0;i--)
        {
            for(int j=0;j<arr.length;j++)
            {

              if(arr[j]>=i)
              {
                System.out.print(" "+i+" ");
              }
             else
              {
                System.out.print("   ");
               }
            } 
            System.out.println(); 
        }
    }
}