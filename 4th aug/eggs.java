import java.util.*;

public class eggs
{
    public static void solve(int e,int f)
    {
        int[][] strg=new int[e+1][f+1];
        for(int i=1;i<strg.length;i++)
        {
            for(int j=1;j<strg[0].length;j++)
            {
                if(i==1 || j==1)
                { 
                    strg[i][j]=j;
                }
                else 
                {
                    int min=99;
                    for(int g=0;g<j;g++)
                    {
                        int val=Math.max(strg[i-1][g],strg[i][j-g-1]);
                        if(val<min)
                        {
                            min=val;
                        }

                    }
                    strg[i][j]=min+1;

                }
            }
        }
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                System.out.print(strg[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println(strg[e][f]);
    }
    public static void main(String[] args)
    {
        solve(2,10);
    }
}