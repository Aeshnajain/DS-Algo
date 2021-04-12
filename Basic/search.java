import java.util.*;

public class search
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the size of array");
        int n;
        n=scn.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("enter the " +(i+1)+ "th value");
            arr[i]=scn.nextInt();
        }
        System.out.print("enter the value to find");
        int m=scn.nextInt();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==m)
            {
                System.out.print("value found at"+(i+1));
                return;
            }
        }
        System.out.print("value not found");
    }

    
}