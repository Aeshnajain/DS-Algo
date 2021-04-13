import java.util.*;

public class mul
{
    public static void main(String[] args)
    {
        int[][] a1={
            {10,0,1},
            {0,1,20}
        };
        int[][] a2={
            {1,1,0,0},
            {0,1,1,0},
            {0,0,1,1}
        }; 
        int[][] pro=new int[a1.length][a2[0].length];
        if(a1[0].length==a2.length)
        {
            for(int i=0;i<a1.length;i++)
            {
                for(int j=0;j<a2[0].length;j++)
                {
                   for(int m=0;m<a1[0].length;m++) 
                   {
                       int sum=a1[i][m]*a2[m][j];
                       pro[i][j]=pro[i][j]+sum;
                   }
                  
                }
            } 
        }
        for(int i=0;i<pro.length;i++)
        {
            for(int j=0;j<pro[0].length;j++)
            {
                System.out.print(" "+pro[i][j]);
            }
            System.out.println();
        }
    }
}