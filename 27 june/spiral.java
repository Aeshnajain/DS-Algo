import java.util.*;
public class spiral
{
    public static void main(String[] args)
    {
        int[][] arr={
            {11,12,13,14,15},
            {21,22,23,24,25},
            {31,32,33,34,35},
            {41,42,43,44,45}
        };
        int dir=0;
        int minr=0;
        int minc=0;
        int maxr=arr.length-1;
        int maxc=arr[0].length-1;
        int val=arr.length*arr[0].length;
        while (dir<val)
        {
            for(int x=minr;x<=maxr;x++)
            {
                System.out.print(" "+arr[x][minc]);
                dir++;

            }
            minc++;
            for(int y=minc;y<=maxc;y++)
            {
                System.out.print(" "+arr[maxr][y]);
                dir++;
            }
            maxr--;
            for(int y=maxr;y>=minr;y--)
            {
                System.out.print(" "+arr[y][maxc]);
                dir++;
            }
            maxc--;
            for(int y=maxc;y>=minc;y--)
            {
                System.out.print(" "+arr[minr][y]);
                dir++;
            }
            minr++;

        }
    }
}      