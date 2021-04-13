import java.util.*;

public class a
{
    public static void ps(int[] arr,int length)
    {
        if(length==0)
        {
            return;
        }
        int[] brr=new int[length-1];
        for(int i=0;i<brr.length;i++)
        {
            brr[i]=arr[i]+arr[i+1];
        }
        ps(brr,brr.length);
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+"\t ");
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        int[] arr={1, 2, 3, 4, 5};
        ps(arr,arr.length);
        
    }
}
