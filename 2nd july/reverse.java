import java.util.*;
//reversing an array using recursion
public class reverse
{
    public static void rev(int[] arr,int l,int r)
    {
        if(l>r)
        {
            return;
        }
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        rev(arr,l+1,r-1);
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50,60};
        rev(arr,0,arr.length-1);
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}