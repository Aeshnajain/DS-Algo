import java.util.*;

public class waved
{
    public static void main(String[] args)
    {
        int[][] arr={
            {11,12,13,14,15},
            {21,22,23,24,25},
            {31,32,33,34,35},
        };
        int dir=0;
        int i=0;
        int j=0;
        while(i<arr.length && j<arr[0].length)
        {
            
            if(dir==0)
            {
              System.out.print(" "+arr[i][j]);
            
                i++;
            }
            else
            {  
                System.out.print(" "+arr[i][j]);
            
                i--;
            }
             if(i==arr.length-1)
            {
                System.out.print(" "+arr[i][j]);
                j++;
               dir=1;
            }
            else if(i==0)
               {
                 System.out.print(" "+arr[i][j]);
            
                  j++;
                  dir=0;
               }
                
           
           
        }
    }
}