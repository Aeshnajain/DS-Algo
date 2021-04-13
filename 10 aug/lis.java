import java.util.*;

public class lis

{
    public static void solve(int[] arr)
    {
        int max=0;
        int max1=Integer.MIN_VALUE;
        int[] strg=new int[arr.length];
        strg[0]=1;
        for(int i=1;i<strg.length;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                {
                    if(strg[j]>max)
                    {
                        max=strg[j];
                    }


                }
            }
            strg[i]=max+1;
        }
        for(int i=0;i<strg.length;i++)
        {
            if(strg[i]>max1)
             max1=strg[i];
        }
        System.out.println(max1);
        printpath(strg);
    }

    public static void printpath(int[] strg)
    {

    }
    public static void main(String[] args)
    {
        int[] arr={10,21,9,33,22,50,41,60,80,7};
        solve(arr);
    }
}