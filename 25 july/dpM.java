import java.util.*;

public class dpM
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

    public static int stairs (int n,int[] qb)
    {
        
         if(n==0)
        {
            return 1;
        }
        else if(n<0)
        {
            return 0;
        }
        else if(qb[n]!=0)
        {
            return qb[n];
        }
        int ans=0;
       for(int i=1;i<=3;i++)
       {
           int a=stairs(n-i,qb);
           ans = ans+a;
       }
       qb[n]=ans;
       return ans;
    }

    public static int stairs2 (int[] arr,int[] qb,int idx)
    { 
        if(idx==arr.length-1)
        {
            return 1;
        }

        else if(idx>=arr.length)
        {
            return 0;
        }
        else if(qb[idx]!=0)
        {
            return qb[idx];
        }
        int ans=0;
        for(int i=1;i<=arr[idx];i++)
        {
            int a=stairs2(arr,qb,idx+i);
            ans=ans+a;

        }

        qb[idx]=ans;
        return ans;

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
        return strg[0];
    }
    static int a=0;
    public static int minpath(int[] arr,int idx,int[] strg)
    {
        if(idx>=arr.length-1)
        {
            return 0;
        }
        else if(strg[idx]!=0)
        {
            return strg[idx];
        }
        for(int i=arr[idx];i>0;i--)
        {
    
          if(arr[i]!=0)
         {
            a=minpath(arr,idx+arr[idx],strg);
            a=a+1;
            break;
         }

        }

        strg[idx]=a;
        return a;

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
        int a=stairs(7,ab);
        System.out.println(a);

        int[] arr={4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
        int[] nans=new int[arr.length+1]; 
        //int ans=stairs2(arr,nans,0);
        int ans=minpath(arr,0,nans);

        System.out.println(ans);

        
    }
}