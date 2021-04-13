import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class mcm
{
    public static void solve(int[] arr)
    {
        int[][] strg=new int[arr.length-1][arr.length-1];
        for(int g=0;g<strg.length;g++)
        {
            for(int i=0;i<strg.length-g;i++)
            {
                int j=i+g;
                if(g==0)
                 strg[i][j]=0;
                else if(g==1)
                 strg[i][j]=arr[i]*arr[j]*arr[j+1];
                else
                {
                    int min=Integer.MAX_VALUE;
                    for(int k=0;k<g;k++)
                    {
                        int l=strg[i][i+k];
                        int r=strg[i+1+k][j];
                        int mult=arr[i]*arr[j+1]*arr[i+k+1];
                        if(l+r+mult<min)
                        {
                            min=l+r+mult;
                        }

                    }
                    strg[i][j]=min;
                }
            }
        }
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg.length;j++)
            {
                System.out.print(strg[i][j]+"\t ");
            }
            System.out.println();
        }
        System.out.println(strg[0][arr.length-2]);
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50,60};
        solve(arr);
    }
}