import java.util.*;

public class rod2
{
    public static void solve(int[] arr)
    {
        int[] strg=new int[arr.length];
        strg[0]=arr[0];
        strg[1]=arr[1];
        for(int i=2;i<strg.length;i++)
        {
            int max=0;
            int l=1;
            int r=i-1;
            while(r>=l)
            {
                if(strg[l]+strg[r]>max)
                 max=strg[l]+strg[r];
                r--;
                l++;

            }
            if(arr[i]>max)
             max=arr[i];
            strg[i]=max;
        }
        System.out.println(strg[strg.length-1]);
    }
    public static void main(String[] args)
    {
        int[] arr={0,3,5,6,15,10,25,12,24};
        solve(arr);
    }
}
