import java.util.*;

public class search
{
    //linear search using recursion
    public static boolean ls(int[] arr,int idx,int key) 
    {
        if(idx==arr.length)
        {
            return false;
        }
        boolean m=ls(arr,idx+1,key);
        if(m==true)
        {
            return m;
        }
        else
        {
            if(arr[idx]==key)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
    }

    // new linear search (better because of less number of calls provided if the
    // key is present in the array as it checks in pre and returns back as soon
    // as the key is found)
    public static boolean nls(int[] arr,int idx,int key)
    {
        if(idx==-1)
        {
            return false;
        }
        if(arr[idx]==key)
        {
            return true;
        }
        else
        {
            boolean x=nls(arr,idx-1,key);
            return x;

        }

    }

     //returning index of first occurence of key

    public static int fs(int[] arr,int idx,int key)
    {
        if(idx==arr.length)
        {
            return -1;
        }
        if(arr[idx]==key)
        {
            return idx;
        }
        else
        {
            int lisa=fs(arr,idx+1,key);
            return lisa;
        }
    }

    //index of last occurence of key
    public static int ms(int[] arr,int idx,int key)
    {
        if(idx==arr.length)
        {
            return -1;
        }
        int misa=ms(arr,idx+1,key);
        if(misa==-1)
        {
            if(arr[idx]==key)
            {
                return idx;
            }
            else
            {
                return misa;
            }
        }
        else{
            return misa;
        }
    }

    //binary search(array containing the indexes of the key)
    public static int[] alloc(int[] arr,int idx,int fsf,int key)
    {
        
        if(idx==arr.length)
        {
          return new int[fsf];
        }
        if(arr[idx]==key)
        {
            fsf=fsf+1;
        }
        int[] brr= alloc(arr,idx+1,fsf,key);
        if(arr[idx]==key)
        {  
            brr[fsf-1]=idx;
            fsf--;
            
        }
       return brr;

    }
    

    public static int[] allindex(int[] arr,int idx,int csf,int key)
    {
        if(idx==arr.length)
        {
            int[] crr= new int[csf];
            return crr;
            
        }
        if(arr[idx]==key)
        {
            int[] crr=allindex(arr,idx+1,csf+1,key);
            crr[csf]=idx;
            return crr;
        }
        else
        {
            int[] crr=allindex(arr,idx+1,csf,key);
            return crr;
        }
        
    
    }



    public static void main(String[] args)
    {
        int[] arr={12,5,6,2,3,2,6,2,6};
        
        boolean m =ls(arr,0,2);
        System.out.println(m);

        boolean x=nls(arr,arr.length-1,0);
        System.out.println(x);

        int n= fs(arr,0,1);
        System.out.println(n);

        int l=ms(arr,0,2);
        System.out.println(l);

        int[] brr=alloc(arr,0,0,2);
        for(int i=0;i<brr.length;i++)
        {
            System.out.print(brr[i]+" ");
        }
        System.out.println();

        int[] crr=allindex(arr,0,0,6);
        for(int i=0;i<crr.length;i++)
        {
            System.out.print(crr[i]+" ");
        }
        
    }
}