import java.util.*;

public class dpT
{
    public static int fibm(int n,int[] qb)
    {
        if(n==0 || n==1)
        {
            return n;
        }
        if(qb[n]!=0)
        {
            return qb[n];
        }
        int fn1=fibm(n-1,qb);
        int fn2=fibm(n-2,qb);
        int fn=fn1+fn2;

        qb[n]=fn;

        return fn;
    }

    public static void stairs (int n)
    {
        int[] strg=new int[n+1];
        strg[n]=1;
        for(int i=strg.length-2;i>=0;i--)
        {
            for(int j=1;j<=3;j++)
            {
                if(i+j<strg.length)
                {
                    strg[i]=strg[i]+strg[i+j];
                }

            }

        }
        System.out.println(strg[0]);
        
         
    }

    public static int stairs2 (int[] arr)
    { 
        int[] strg=new int[arr.length];
        strg[arr.length-1]=1;
        for(int i=strg.length-2;i>=0;i--)
        {
            for(int j=i+1;j<=i+arr[i] && j<arr.length;j++)
            {
                strg[i]=strg[i]+strg[j];
            }
        }
        return strg[0];

    }

    public static int minpath(int[] arr)
    {
        
        int[] strg=new int[arr.length];
        strg[strg.length-1]=0;
        for(int i=strg.length-2;i>=0;i--)
        {
            int min=1000;
    
            for(int j=i+1;j<=i+arr[i] && j<arr.length;j++)
            {
                if(strg[j]<min)
                {
                    min=strg[j];
                
                }

            }
            strg[i]=min+1;
            

        }

        // for(int i=0;i<strg.length;i++)
        // {
        //     System.out.print(strg[i]+" ");
        // }
        return strg[0];
    }
    
    public static void main(String[] args)
    {
        int n=44;
        int[] qb=new int[n+1];
        long start=System.currentTimeMillis();
        int fn=fibm(n,qb);
        long end=System.currentTimeMillis();
        long dur=end-start;
        System.out.println(fn+" @ "+dur);
        int[] ab=new int[8] ;
        stairs(7);

        int[] arr={4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
        int[] nans=new int[arr.length+1]; 
        int mans=stairs2(arr);
        int ans=minpath(arr);

        System.out.println(mans);

        
    }
}