import java.util.*;

public class queens2
{

    static int counter=1;

     public static boolean issafe(boolean[][] arr,int row,int column)
    {
        for(int i=row;i>=0;i--)
        {
            if(arr[i][column]==true)
            {
                return false;
            }
        }
        for(int j=column;j>=0;j--)
        {
            if(arr[row][j]==true)
            {
                return false;
            }
        }
        for(int i=row , j=column;i>=0 && j>=0; i-- , j--)
        {
            if(arr[i][j]==true)
            {
                return false;
            }
        }
         for(int i=row , j=column;i>=0 && j<arr[0].length; i-- , j++)
        {
            if(arr[i][j]==true)
            {
                return false;
            }
        }
        
         return true;   
    }
    
    public static void pq(boolean[][] arr,int i,int j,int qsf, String asf)
    {
        if(i==arr.length && j==0)
        {
            if(qsf==arr.length)
            {
                System.out.println((counter++) +" "+ asf );
            }
            return;
        }
        else if(j<arr.length-1)
        {
            pq(arr,i,j+1,qsf,asf);

            if(issafe(arr,i,j)==true)
            {
                arr[i][j]=true;
                pq(arr,i,j+1,qsf+1,asf+i+j+" ");
                arr[i][j]=false;
            }
        }
        else
        {
           pq(arr,i+1,0,qsf,asf);

            if(issafe(arr,i,j)==true)
            {
                arr[i][j]=true;
                pq(arr,i+1,0,qsf+1,asf+i+j+" ");
                arr[i][j]=false;
            } 

        }
    }
    public static void main(String[] args)
    {
        boolean[][] arr=new boolean[4][4];
        pq(arr,0,0,0,"");
    }
}