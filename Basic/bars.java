import java.util.*;

public class bars
{
    public static void main(String[] args)
    {
        int[] arr={4,7,2,8,5};
        int max=arr[0];
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            
            }
        }
        for(int i=max;i>0;i--)
        {    
            for(int m=0;m<arr.length;m++)
            {
                if(arr[m]<i)
                {
                    System.out.print("     ");
                }
                else
                {
                    System.out.print("  *  ");
                }
            }
            System.out.println();
           
        }

    }
}