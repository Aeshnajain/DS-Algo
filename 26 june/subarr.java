import java.util.*;

public class subarr
{
    public static void main(String[] args)
     {
         int[] arr={2,4,3,-6,-4,1,7,-2,6,4,-3,2,3,-9,-6,-4,4,8};
         int cs=0;
         int ce=0;
         int css=arr[0];

         int bs=0;
         int be=0;
         int bss=arr[0];

         for(int i=1;i<arr.length;i++)
         {
             if(css>0)
             {
                 ce++;
                 css=css+arr[i];
             }
             else
             {
                 cs=i;
                 ce=i;
                 css=arr[i];
             }
             if(css>bss)
             {
                 bs=cs;
                 be=ce;
                 bss=css;
             }
         }
         for(int i=bs;i<=be;i++)
         {
             System.out.print(arr[i]+" ");
         }


     }
}