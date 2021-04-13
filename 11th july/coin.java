import java.util.*;

//permutation_with_duplicacy

public class coin
{
    public static void pp(int[] arr,int amt,String asf)
    {
        if(amt==0)
        {
            System.out.println(asf);
        }
        for(int i=0;i<arr.length;i++)
        {
            if(amt-arr[i]>=0)
            {
                pp(arr,amt-arr[i],asf+arr[i]);
            }
        }
    }
    public static void main(String[] args)
    {
       int[] arr={2,3,5,6};
       pp(arr,7,"");
    }
}