import java.util.*;

public class subsets
{
    public static void solve(int[] arr,int t)
    {
        boolean[][] ans=new boolean[arr.length][t+1];
        ans[0][0]=true;
        if(arr[0]<ans[0].length){
            ans[0][arr[0]]=true;
        }
        for(int i=1;i<ans.length;i++)
        {
            for(int j=0;j<ans[0].length;j++)
            { 
                if(j==0)
                {
                    ans[i][j]=true;
                }
                else if(ans[i-1][j]==true)
                {
                    ans[i][j]=true;
                }
                else
                {
                    int m=j-arr[i];
                    if(arr[i]<ans.length)
                    {
                     ans[i][arr[i]]=true;
                    }
                    if(m>=0 && m<ans[0].length && ans[i-1][m]==true)
                    {
                        ans[i][j]=true;
                        
                    }
                }
                
            }
        
        }
        

        System.out.println(ans[ans.length-1][ans[0].length-1]);
        paths(ans,ans.length-1,ans[0].length-1,arr,"");
        


    }

    public static void paths(boolean[][] ans,int r,int c,int[] arr,String psf)
    {
        if(r==0)
        {
            if(c==0)
            {
                System.out.println(psf);
            }
            else
            {
                System.out.println(psf+arr[0]);
            }

        }
        else
        {
        if(ans[r-1][c]==true)
         {
            paths(ans,r-1,c,arr,psf);
         }
        if(c>=arr[r])
          {
            if(ans[r-1][c-arr[r]]==true)
            {
                paths(ans,r-1,c-arr[r],arr,psf+arr[r]+" ");
            }
          }
        }
    }

    public static void permcount(int[] arr,int t)
    {
        int[] strg=new int[t+1];
        strg[0]=1;
        for(int i=1;i<strg.length;i++)
        {
            for(int j=0;j<arr.length;j++)
            {
                if(i>=arr[j]){
                 strg[i]+=strg[i-arr[j]];
                }
            }
        }
        System.out.println(strg[t]);
        

    }

    public static void combcount(int[] arr,int t)
    {
        int[] strg=new int[t+1];
        strg[0]=1;
        for(int i=0;i<arr.length;i++)
        {
            for(int j=1;j<strg.length;j++)
            {
                if(j>=arr[i])
                 strg[j]+=strg[j-arr[i]];
            }
        }
        System.out.println(strg[t]);

    }
    
    public static void main(String[] args)
    {
        int[] arr={3,2,5,1,8};
        int n=9;
        solve(arr,n);
        

        int[] brr={2,3,5,6};
        int t=7;
        permcount(brr,t);
        combcount(brr,t);
    }
}