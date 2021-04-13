import java.util.*;

public class friends
{
    public static void solve(int n)
    {
        int[] strg=new int[n+1];
        strg[0]=1;
        strg[1]=1;
        strg[2]=2;
        for(int i=3;i<strg.length;i++)
        {
            strg[i]=strg[i-1]+(i-1)*strg[i-2];

        }
        System.out.println(strg[n]);
    }

    public static void tiles(int n,int m )
    {
        int[] strg=new int[n+1];
        strg[0]=0;
        strg[1]=1;
        for(int i=2;i<strg.length;i++)
        {
            if(i-m>=0)
            {
               strg[i]=strg[i-1]+strg[i-m];
            }
            else
            {
                strg[i]=strg[i-1];
            }
        }
        System.out.println(strg[n]);

    }
    public static void main(String[] args)
    {
        int p=3;
        solve(p);
        tiles(15,3);

    }
}