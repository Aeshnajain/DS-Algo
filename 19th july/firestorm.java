import java.util.*;

public class firestorm
{
    static class point
    {
        int x;
        int y;
        int t;
    }
    public static void solve(int[][] arr,int t)
    {
        ArrayDeque<point> q=new ArrayDeque<>();
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                if(arr[i][j]==1)
                {
                  point p=new point();
                  p.x=i;
                  p.y=j;
                  p.t=1;
                  q.addLast(p);

                }
            }
        }
        while(q.size()>0)
        {
            point rem=q.getFirst();
            q.removeFirst();
            if(rem.t==t+2)
            {
                break;
            }
            if(arr[rem.x][rem.y]<0)
            {
                continue;
            }

            arr[rem.x][rem.y]=-rem.t;

            if(rem.x-1>=0 && arr[rem.x-1][rem.y]==0)
            {
                point p=new point();
                p.x=rem.x-1;
                p.y=rem.y;
                p.t=rem.t+1;
                q.addLast(p);
            }
            if(rem.x+1<arr.length && arr[rem.x+1][rem.y]==0)
            {
                point p=new point();
                p.x=rem.x+1;
                p.y=rem.y;
                p.t=rem.t+1;
                q.addLast(p);
            }
            if(rem.y-1>=0 && arr[rem.x][rem.y-1]==0)
            {
                point p=new point();
                p.x=rem.x;
                p.y=rem.y-1;
                p.t=rem.t+1;
                q.addLast(p);
            }
            if(rem.y+1<arr[0].length && arr[rem.x][rem.y+1]==0)
            {
                point p=new point();
                p.x=rem.x;
                p.y=rem.y+1;
                p.t=rem.t+1;
                q.addLast(p);
            }
        }
    }
    public static void main(String[] args)
    {
        int[][] arr={
            {1,2,0,2,0,0,0},
            {0,2,0,2,0,1,0},
            {0,0,0,2,0,0,0},
            {2,2,2,2,2,2,0},
            {0,2,1,0,0,0,0},
            {0,2,0,0,0,0,0},
            {0,2,0,0,0,0,0},
        };
        solve(arr,3);
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }

    }
}