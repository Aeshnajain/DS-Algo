import java.util.*;

public class func
{
    public static void rev(int[] arr)
    {
        int left=0;
        int right=arr.length-1;
        while(left<right)
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;

            left++;
            right--;
        }
    }
    public static void display(int[] arr)
    {
         for(int i=0;i< arr.length;i++)
        {
            System.out.print(arr[i]+ " ");
        }
      
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50,60};
        rev(arr);
        display(arr);
       
    }
}