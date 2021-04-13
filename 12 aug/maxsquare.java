import java.util.*;

public class maxsquare{

    public static void solve(int[][] maze)
    {
        int[][] strg=new int[maze.length][maze[0].length];
        for(int i=strg.length-1;i>=0;i--)
        {
            for(int j=strg[0].length-1;j>=0;j--)
            {
                if(maze[i][j]==0)
                 strg[i][j]=0;
                else if(i==strg.length-1 || j==strg[0].length-1)
                 strg[i][j]=maze[i][j];
                else 
                 strg[i][j]=Math.min(strg[i+1][j],Math.min(strg[i][j+1],strg[i+1][j+1]))+1;
            }
        }
        int max=0;
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                if(strg[i][j]>=max)
                 max=strg[i][j];
            }
        }
        System.out.println(max);
    }
    public static void main(String[] args)
    {
        int[][] maze={
            {1,0,0,1,0,0,1,0},
            {1,1,1,1,1,1,1,1},
            {1,1,0,1,1,1,1,0},
            {1,0,1,1,1,1,1,0},
            {0,1,1,1,1,1,1,1},
            {1,0,1,0,1,1,0,1},
            {1,0,0,1,1,1,1,1},
        };
        solve(maze);
    }
}