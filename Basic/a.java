import java.io.*;
import java.util.*;

public class a {

    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int[] arr=new int[n];
        
        for(int i=0;i<arr.length;i++)
        {
            arr[i]=scn.nextInt();
        }
        int val=scn.nextInt();
        for(int i=0;i<arr.length;i++)
        {
        
            for(int j=i+1;j<arr.length;j++)
            {
               int temp=val-arr[i];
                temp=temp-arr[j];
                for(int m=j+1;m<arr.length;m++)
                {
                    if(arr[m]==temp)
                    {
                        System.out.print(arr[i]+", "+arr[j]+" and "+arr[m]);
                        
                    }
                }
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}