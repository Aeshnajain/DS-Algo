import java.util.*;

public class queens
{
    static int counter=1;

    public static boolean issafe(boolean[][] arr,int row,int column)
    {
        int a=0;
        for(int i=row;i>=0;i--)
        {
            if(arr[i][column]==true)
            {
                a++;
                break;
            }
        }
        for(int i=column;i>=0;i--)
        {
            if(arr[row][i]==true)
            {
                a++;
                break;
            }
        }
        for(int i=row,j=column; i>=0 && j>=0; i--,j--)
        {
            if(arr[i][j]==true)
            {
                a++;
                break;
            }
            
        }
         for(int i=row,j=column; i>=0 && j<arr[0].length; i--,j++)
        {
            if(arr[i][j]==true)
            {
                a++;
                break;
            }
        }
        if(a>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public static void pq(boolean[][] arr,int iq,int fq,String asf,int start1,int start2)
    {
        if(iq==fq)
        {
            System.out.println((counter++)+" " + asf);
            return;
        }
        for(int i=start1;i<arr.length;i++)
        {
            for(int j=i==start1?start2+1:0;j<arr[0].length;j++)
            {
                if(arr[i][j]==false && issafe(arr,i,j)==false)
                {
                    arr[i][j]=true;
                    pq(arr,iq+1,fq,asf+i+j+" ",i,j);
                    arr[i][j]=false;
                }
            }
        }
    }
    public static void main(String[] args)
    {
        boolean[][] arr=new boolean[4][4];
        pq(arr,0,4,"",0,-1);
    }
}