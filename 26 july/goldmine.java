import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class goldmine
{
    public static void solve(int[][] local)
    {
        int[][] global=new int[local.length][local[0].length];
        for(int j=global[0].length-1;j>=0;j--)
        {
            for(int i=0;i<global.length;i++)
            {
                if(j==global[0].length-1)
                {
                    global[i][j]=local[i][j];
                }
                else if(i==0)
                {
                    global[i][j]=local[i][j]+Math.max(global[i+1][j+1],global[i][j+1]);
                }
                else if(i==global.length-1)
                {
                    global[i][j]=local[i][j]+Math.max(global[i-1][j+1],global[i][j+1]);
                }
                else
                {
                    int m=Math.max(global[i-1][j+1],global[i+1][j+1]);
                    int ans=Math.max(m,global[i][j+1]);
                    global[i][j]=local[i][j]+ans;
                }
            }

        }
        int max=-1;
        for(int i=0;i<global.length;i++)
        {
            if(global[i][0]>max)
            {
                max=global[i][0];
            }
            
        }
        System.out.println(max);
    }
    public static void main(String[] args)
    {
        int[][] local={
            {1,5,1,0,3},
            {1,4,0,2,3},
            {4,0,1,3,2},
            {2,4,0,4,1},
            {1,2,3,2,0},

        };
        solve(local);
    }
}