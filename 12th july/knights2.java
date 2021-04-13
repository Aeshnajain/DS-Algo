import java.util.*;

public class knights2
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
    
    public static void pk(boolean[][] arr,int i,int j,int ksf, String asf)
    {
        if(i==arr.length && j==0)
        {
            if(ksf==arr.length)
            {
                System.out.println((counter++) +" "+ asf );
            }
            return;
        }
        else if(j<arr.length-1)
        {
            pk(arr,i,j+1,ksf,asf);

            if(issafe(arr,i,j)==true)
            {
                arr[i][j]=true;
                pk(arr,i,j+1,ksf+1,asf+i+j+" ");
                arr[i][j]=false;
            }
        }
        else
        {
           pk(arr,i+1,0,ksf,asf);

            if(issafe(arr,i,j)==true)
            {
                arr[i][j]=true;
                pk(arr,i+1,0,ksf+1,asf+i+j+" ");
                arr[i][j]=false;
            } 

        }
    }
    public static void main(String[] args)
    {
        boolean[][] arr=new boolean[3][3];
        pk(arr,0,0,0,"");
    }
}