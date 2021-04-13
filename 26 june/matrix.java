import java.util.*;

public class matrix
{
    public static void main(String[] args)
    {
        int[][] arr={
            {0,0,1,0},
            {1,0,0,0},
            {0,0,0,0},
            {1,0,1,0}
        };
        int dir=0;
        int i=0;
        int j=0;
        while(i<arr.length && j<arr[0].length && i>=0 && j>=0)
        {
            dir=dir+arr[i][j];
            dir=dir%4;
            
           if( dir==0)
           {
               j++;
            }
           else if( dir==1)
           {
               i++;
            }
           else if( dir==2)
           {
               j--;
            }
           else
           {
               i--;
            }
        }
        if(i==arr.length)
        {
            i--;
        }
        else if(i<0)
        {
            i++;
        }
        else if(j<0)
        {
            j++;
        }
        else
        {
            j--;
        }
        System.out.println("the indices of exit point are ["+i+","+j+"]");
    }

}