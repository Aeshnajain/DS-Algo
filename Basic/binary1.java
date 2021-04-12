import java.util.*;

public class binary1
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int[] arr={ 10,10,10,20,20,20,30,30,40,50,50,50};
        Arrays.sort(arr);
        System.out.print("enter the value");
        int data=scn.nextInt();
        int left=0;
        int right= arr.length-1;
        int result=-1;
        while(left<=right)
        { 
            int mid=(left + right)/2;
            if(data>arr[mid])
            {
                left=mid+1;
            }
            else if(data<arr[mid])
            {
                right=mid-1;
            }
            else
            {
                result=mid;
                right=mid-1;
                
            }

        }
        if(result==-1)
        {
           System.out.print("data not found");
        }
        else
        {
            System.out.print("data found at "+result);
        }
    }
}