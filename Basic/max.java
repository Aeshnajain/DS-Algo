import java.util.*;

public class max
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int[] arr=new int[6];
        for(int i=0;i<arr.length;i++)
        {
            System.out.print("enter the " +(i+1)+ " th number of the array");
            arr[i]=scn.nextInt();
        }
        int max=arr[0];
        for(int i=1;i<arr.length;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        System.out.print("maximum value is "+max);
    }
}