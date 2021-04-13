import java.util.*;
//combination with duplicacy
public class coinc
{
    public static void pp(int[] arr,int amt,String asf,int start)
    {
        if(amt==0)
        {
            System.out.println(asf);
        }
        for(int i=start;i<arr.length;i++)
        {
            if(amt-arr[i]>=0)
            {
                 pp(arr,amt-arr[i],asf+arr[i],i);
            }
        }
    }
    public static void main(String[] args)
    {
       int[] arr={1,3,5,6};
       pp(arr,7,"",0);
    }
}