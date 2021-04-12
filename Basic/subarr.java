import java.util.*;
public class subarr
{
    public static void main(String[] args)
    {
        int[] arr1={9, 3, 4, 5, 2};
        int[] arr2={2, 6, 7, 9 };
        int[] sub=new int[arr1.length>arr2.length?arr1.length:arr2.length];

        int i=arr1.length-1;
        int j=arr2.length-1;
        int k=sub.length-1;
        int digit=0;
        while(k>=0)
        {
              if(arr2[j]>0)
              {
                  if(arr2[j]>arr1[i])
                  {
                      if(arr2[j+1]>arr1[i+1] && i!=arr1.length-1 && j!=arr2.length-1)
                      {
                           digit=(9+arr1[i])-arr2[j];
                      }
                      else
                      {
                           digit=(10+arr1[i])-arr2[j];
                      }
                  }
                  else
                  {
                       digit= arr1[i]-arr2[j];
                  }
              }
              else
              {
                   digit=arr1[i];
              }
              sub[k]=digit;
                
            }
            i--;
            j--;
            k--;
        
        for(int m=0;m<sub.length;m++)
        {
            System.out.print(+sub[m]);
        }
    }
}