import java.util.*;

public class transpose
{
    public static void main(String[] args)
    {
        int[][] arr={
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        };
        for(int i=0;i<arr.length;i++)
        {
            for(int j=i+1;j<arr[0].length;j++)
            {
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
        int left=0;
        int right=arr.length-1;
        for(int i=0;i<arr.length;i++)
        {
            while(left>right)
            {
              arr[i][left]=arr[i][right];
              left++;
              right--;
            }
        }
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                System.out.print(" "+arr[i][j]);
            }
            System.out.println();
        }
    }
}