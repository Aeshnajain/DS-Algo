import java.util.*;

public class binary
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int[] arr={ 20,30,40,50,60,70,100,140,30,10};
        Arrays.sort(arr);
        System.out.print("enter the value");
        int data=scn.nextInt();
        int left=0;
        int right= arr.length-1;
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
                System.out.print(data+ " found at " +mid);
                return;
            }

        }
        System.out.print("data not found");

    }
}