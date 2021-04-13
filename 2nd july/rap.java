import java.util.*;
//reverse array printing using recursion
public class rap
{
    public static void pa(int[] arr,int idx)
    {
        if(idx==-1)
        {
            return;
        }
        System.out.println(arr[idx]);
        pa(arr,idx-1);
    }
    public static void main(String[] args)
    {
        int[] arr={10,20,30,40,50};
        pa(arr,arr.length-1);
    }
}