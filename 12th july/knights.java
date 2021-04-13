import java.util.*;

public class knights
{
    static int counter=1;

    public static boolean issafe(boolean[][] arr,int row,int column)
    {
        if(row-1>=0 && column-2>=0)
        {
            if(arr[row-1][column-2]==true)
            {
                return false;
            }
        }
         if(row-2>=0 && column-1>=0)
        {
            if(arr[row-2][column-1]==true)
            {
                return false;
            }
        }
         if(row-1>=0 && column+2<arr[0].length)
        {
            if(arr[row-1][column+2]==true)
            {
                return false;
            }
        }
         if(row-2>=0 && column+1<arr[0].length)
        {
            if(arr[row-2][column+1]==true)
            {
                return false;
            }
        }
        
         return true;
    
        
            
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
            for(int j=(i==start1)?start2+1:0;j<arr[0].length;j++)
            {
                if(arr[i][j]==false && issafe(arr,i,j)==true)
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