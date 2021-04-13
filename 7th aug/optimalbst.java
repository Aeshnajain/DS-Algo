import java.util.*;

public class optimalbst
{
    public static void solve(int[] arr,int[] f)
    {
        int[][] strg=new int[arr.length][arr.length];
        int left=0;
        int right=0;
        int[] psa=new int[f.length];
        psa[0]=f[0];
        for(int i=1;i<psa.length;i++)
        {
            psa[i]=psa[i-1]+f[i];

        }

        for(int g=0;g<strg.length;g++)
        {
            for(int i=0;i<strg.length-g;i++)
            {
                int j=i+g;
                if(g==0)
                 strg[i][j]=f[i];
                else if(g==1)
                 strg[i][j]=2*strg[i][j-1]+strg[i+1][j]>2*strg[i+1][j]+strg[i][j-1]?2*strg[i+1][j]+strg[i][j-1]:2*strg[i][j-1]+strg[i+1][j];
                else
                {
                    int min=Integer.MAX_VALUE;
                    for(int k=0;k<=g;k++)
                    {
                        left=k==0?0:strg[i][i+k-1];
                        right=k==g?0:strg[i+k+1][j];
                        int ans=left+right;
                        if(min>ans)
                         min=ans;
                    }
                    // for(int m=i;m<=j;m++)
                    // {
                    //      min+=f[m];
                    // }
                    // strg[i][j]=min;
                    strg[i][j]=min+psa[j];
                    if(i>0)
                     strg[i][j]-=psa[i-1];
                }
            }

        }
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                System.out.print(strg[i][j]+"  ");
            }
            System.out.println();
        }
        System.out.println(strg[0][strg[0].length-1]);
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50,60,70};
        int[] f={2,1,4,1,1,3,5};
        solve(arr,f);

    }
}