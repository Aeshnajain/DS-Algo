import java.util.*;
//recursion with array
//printing the array using recursion
public class rwa
{
    public static void pa(int[] arr,int idx)
    {
        if(idx==arr.length)
        {
            return;
        }
        System.out.println(arr[idx]);
        pa(arr,idx+1);
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50};
        pa(arr,0);
    }
}