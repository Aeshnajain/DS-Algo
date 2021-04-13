import java.util.*;

public class coingame
{
    public static void solve(int[] arr)
    {
        int[][] strg=new int[arr.length][arr.length];

        for(int g=0;g<strg.length;g++)
        {
            for(int i=0;i<strg.length-g;i++)
            {
                int j=i+g;
                if(g==0)
                 strg[i][j]=arr[i];
                else if(g==1)
                 strg[i][j]=Math.max(strg[i][j-1],strg[i+1][j]);
                else
                {
                    if(g%2!=0)
                    {
                        int min1=strg[i+2][j]>strg[i+1][j-1]?strg[i+1][j-1]:strg[i+2][j];
                        min1+=arr[i];
                        int min2=strg[i][j-2]>strg[i+1][j-1]?strg[i+1][j-1]:strg[i][j-2];
                        min2+=arr[j];
                        strg[i][j]=min1>min2?min1:min2;
                    }
                    else
                     continue;
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
        System.out.println(strg[0][arr.length-1]);
    }
    public static void main(String[] args)
    {
        int[] arr={20,30,2,2,2,10};
        solve(arr);
    }
}