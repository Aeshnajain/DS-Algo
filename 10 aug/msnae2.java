import java.util.*;

public class msnae2
{
    public static int solve(int[] arr)
    {
        int[] strg=new int[arr.length];
        strg[0]=arr[0];
        strg[1]=arr[1];
        for(int i=2;i<arr.length;i++)
        {
            strg[i]=arr[i];
            for(int j=i-2;j>=0;j--)
           {
                strg[i]=strg[j]+arr[i]>strg[i]?strg[j]+arr[i]:strg[i];
           }
        }
        return strg[arr.length-1];
    }
    public static void main(String[] args)
    {
        int[] arr={5,-6,-10,-100,-10,5};
        long n=System.currentTimeMillis();
        int ans=solve(arr);
        long m=System.currentTimeMillis();
        System.out.println(ans);
        System.out.println(m-n);
    }


}