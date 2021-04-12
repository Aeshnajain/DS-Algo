import java.util.*;

public class sumarr
{
    public static void main(String[] args)
    {
        int[] n1={9, 7, 2, 9};
        int[] n2={9, 6, 9, 9, 8, 9};
        int[] sum= new int[n1.length>n2.length?n1.length+1:n2.length+1];
        int n=0;

            for(int i=sum.length-1;i>=0;i--)
            {
                int m=n1[n1.length]+n2[n2.length]+n;
                if(m>9)
                {
                    m=m%10;
                    n=m/10;
                
                }
                else
                { 
                     n=0;
                }
                for(int j=0;j<sum.length;j++)
                {
                    sum[i]=m;
                    System.out.print(sum[i]);
                }
                
                
            }
        }
    }
}