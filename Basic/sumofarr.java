import java.util.*;

public class sumofarr
{
    public static void main(String[] args)
    {
        int[] n1={9, 7, 2, 9};
        int[] n2={9, 6, 9, 9, 8, 9};
        int[] sum= new int[n1.length>n2.length?n1.length+1:n2.length+1];
        
        int i=n1.length-1;
        int j=n2.length-1;
        int k=sum.length-1;
        int carry=0;
        while(k>=0)
        {
            int var=carry;
            if(i>=0)
            {
                var=var+n1[i];
            }
            if(j>=0)
            {
                var=var+n2[j];
            }
            int digit=var%10;
            carry=var/10;

            sum[k]=digit;
            i--;
            j--;
            k--;
        }
        for(int i=0;i<sum.length;i++)
        {
            if(i==0 && sum[i]==0)
            {
                continue;
            }
            System.out.print(sum[i]);
        }
    }
}       