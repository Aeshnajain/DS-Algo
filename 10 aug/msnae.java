import java.util.*;

public class msnae
{
    public static void solve(int[] arr)
    {
        int[] inc=new int[arr.length];
        int[] exc=new int[arr.length];

        inc[0]=arr[0];
        for(int i=1;i<arr.length;i++)
        {
            inc[i]=exc[i-1]+arr[i];
            exc[i]=Math.max(inc[i-1],exc[i-1]);
        }
        int ans=Math.max(inc[arr.length-1],exc[arr.length-1]);
        System.out.println(ans);
    }
    public static void main(String[] args)
    {
        int[] arr={5,6,10,100,10,5};
        solve(arr);
    }


}