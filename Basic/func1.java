import java.util.*;

public class func1
{
    public static void swap(int[] arr,int a,int b)
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    public static void rev(int[] arr)
    {
        int left=0;
        int right=arr.length-1;
        while(left<right)
        {
            swap(arr,left,right);
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