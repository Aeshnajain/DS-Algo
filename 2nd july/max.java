import java.util.*;

public class max
{
    public static int max(int[] arr,int idx)
    {
        if(idx==arr.length-1)
        {
            return arr[idx];
        }
        int m=max(arr,idx+1);
        if(m>arr[idx])
        {
            return m;
        }
        else
        {
           return arr[idx];
        }
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50};
        int m=max(arr,0);
        System.out.print(+m);
    }
}