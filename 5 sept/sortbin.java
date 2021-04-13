import java.util.*;

public class sortbin

{
    public static void swap(int[] arr,int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    public static void sort(int[] arr)
    {
        int i=0;
        int j=0;
        while(j<arr.length)
        {
            if(arr[j]==1)
            {
                j++;
            }
            else if(arr[j]==0)
            {
                swap(arr,i,j);
                j++;
                i++;
            }
        }
    }

    public static void sort2(int[] brr)
    {
        int i=0;
        int j=0;
        int k=brr.length-1;
        while(k>=i)
        {
            if(brr[i]==1)
            {
                i++;
            }
            else if(brr[i]==0)
            {
                swap(brr,i,j);
                j++;
                i++;
            }
            else
            {
                swap(brr,i,k);
                k--;
            }
        }
        
    }

    static int invcount=0;

    public static int[] getmergesort(int[] la,int[] ra)
    {
        int x=0;
        int y=0;
        int z=0;

        int[] sa=new int[la.length+ra.length];

        while(x<la.length && y<ra.length)
        {
            if(la[x]<ra[y])
            {
                sa[z++]=la[x++];
            }
            else
            {
                sa[z++]=ra[y++];
                invcount+=la.length-x;
                
            }

        }

        while(x<la.length)
        {
            sa[z++]=la[x++];

        }
        while(y<ra.length)
        {
            sa[z++]=ra[y++];
        }

        return sa;
    }

    public static int[] mergesort(int[] arr,int lo,int hi)
    {
        if(lo==hi)
        {
            int[] brr=new int[1];
            brr[0]=arr[lo];
            return brr;

        }
        int mid=(lo+hi)/2;
        int[] lh=mergesort(arr,lo,mid);
        int[] rh=mergesort(arr,mid+1,hi);
        int[] sa=getmergesort(lh,rh);

        return sa;

    }

    public static int partitioning(int[] arr,int lo,int hi)
    {
        int pivot=arr[hi];
        int i=lo;
        int j=lo;
        while(i<=hi)
        {
            if(arr[i]<=pivot)
            {
                swap(arr,i,j);
                i++;
                j++;

            }
            else
            {
                i++;
            }


        }
        return j-1;
    }

    // public static int quickselect(int[] arr,int lo,int hi,int k)
    // {
    //     int pi=partitioning(arr,lo,hi);
    //     while(pi!=k-1)
    //     {
    //         if(pi<k-1)
    //         {
    //             pi=partitioning(arr,pi+1,hi);
    //         }
    //         else if(pi>k-1)
    //         {
    //             pi=partitioning(arr,lo,pi-1);
    //         }
    //     }
    //     return arr[pi];
    // }

    public static void quicksort(int[] arr,int lo,int hi)
    {
        if(lo==hi)
        {
            return;
        }
        int pi=partitioning(arr,lo,hi);
        quicksort(arr,lo,pi-1);
        quicksort(arr,pi+1,hi);
    }

    public static int quickselectrec(int[] arr,int lo,int hi,int k)
    {
        int pi=partitioning(arr,lo,hi);
        if(pi<k-1)
        {
            pi=quickselectrec(arr,pi+1,hi,k);
        }
        else if(pi>k-1)
        {
            pi=quickselectrec(arr,lo,pi-1,k);
        }
        return pi;
    }

    public static int[] countsort(int[] input)
    {
        int n=input.length;
        int r=10;
        int[] fm=new int[r];

        for(int val:input)
        {
            fm[val]++;
        }

        for(int i=1;i<fm.length;i++)
        {
            fm[i]+=fm[i-1];
        }

        int[] out=new int[n];

        for(int i=input.length-1;i>=0;i--)
        {
            int val=input[i];
            fm[val]--;
            out[fm[val]]=val;

        }

        return out;

    }

    public static int[] countsortforrs(int[] input,int div)
    {
        int n=input.length;
        int r=10;
        int[] fm=new int[r];

        for(int val:input)
        { 
            val=(val/div)%10;
            fm[val]++;
        }

        for(int i=1;i<fm.length;i++)
        {
            fm[i]+=fm[i-1];
        }

        int[] out=new int[n];

        for(int i=input.length-1;i>=0;i--)
        {
            int val=input[i];
            val=(val/div)%10;
            fm[val]--;
            out[fm[val]]=input[i];

        }

        return out;

    }

    public static void radixsort(int[] input)
    {
        int max=0;
        for(int val:input)
        {
            max=Math.max(max,val);
        }

        int div=1;
        while(max/div>0)
        {
            input=countsortforrs(input,div);
            System.out.println(Arrays.toString(input));
            div*=10;
        }

    }

    public static void maxfreqchar(String s)
    {
        int[] fm=new int[26];
        for(int i=0;i<s.length();i++)
        {
            fm[s.charAt(i)-97]++;
        }
        int mx=0;
        int idx=0;
        for(int i=0;i<fm.length;i++)
        {
            if(fm[i]>=mx)
            {
                mx=fm[i];
                idx=i;
            }

        }

        System.out.println((char)(idx+97));

    }
    public static void main(String[] args)
    {
        //int[] arr={0,1,1,1,0,0,1};
        // sort(arr);
        // for(int i=0;i<arr.length;i++)
        // {
        //     System.out.print(arr[i]);
        // }
        // System.out.println();

        // int[] brr={1,1,0,0,1,2,0,1,2,2,0,1,0};
        // sort2(brr);

        // for(int i=0;i<brr.length;i++)
        // {
        //     System.out.print(brr[i]);
        // }
        // System.out.println();
        String s="abbcdabccd";
        maxfreqchar(s);
        int[] arr={234,512,125,82,600,32,71,498};

        //int[] sa=mergesort(arr,0,arr.length-1);
        // int ans=quickselectrec(arr,0,arr.length-1,2);
        // System.out.println(arr[ans]);
        //quicksort(arr,0,arr.length-1);

        //int[] sa=countsort(arr);
        radixsort(arr);

        //System.out.println(Arrays.toString(arr));
        //System.out.println(invcount);
    }
}