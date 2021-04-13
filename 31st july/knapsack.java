import java.util.*;

public class knapsack
{
    public static void solve(int[] wt,int[] p,int t)
    {
        int[][] strg=new int[wt.length][t+1];
        
        for(int i=0;i<strg.length;i++)
        {
            for(int j=1;j<strg[0].length;j++)
            {
                if(i==0)
                {
                    if(j-wt[i]>=0)
                     strg[i][j]=p[i];
                }
                else  
                {
                    strg[i][j]=strg[i-1][j];
                    if(j-wt[i]>=0)
                    {
                        int fact=p[i]+strg[i-1][j-wt[i]];
                        if(fact>strg[i][j])
                        {
                            strg[i][j]=fact;
                        }
                    }
                }
                

            }

        }
        System.out.println(strg[wt.length-1][t]);

        path(strg,strg.length-1,t,wt,p,"");
    }

    public static void path(int[][] strg,int r,int c,int[] wt,int[] p,String asf)
    {
        if(r==0)
        {
            if(c==0)
            {
                System.out.println(asf);

            }
            else
            {
                System.out.println(wt[0]+" "+asf);
            }
        }
        else
        {
            if(strg[r-1][c]==strg[r][c])
            {
                path(strg,r-1,c,wt,p,asf);
            }
            int fact=strg[r][c]-p[r];
            int idx=c-wt[r];
            if(idx>=0 && fact==strg[r-1][idx])
            {
                path(strg,r-1,idx,wt,p,wt[r]+" "+asf);
            }
            
        }

    }

    public static void knapsackub(int[] wt,int[] p,int t)
    {
        int[] strg=new int[t+1];
        strg[0]=0;
        for(int i=1;i<strg.length;i++)
        {
            for(int j=0;j<wt.length;j++)
            {
                if(i-wt[j]>=0)
                {
                    int fact=p[j]+strg[i-wt[j]];
                    if(fact>strg[i])
                    {
                        strg[i]=fact;
                    }

                  
                }
            }
        }
        System.out.println(strg[t]);
    }

    public static void knapsackcomb(int[] wt,int[] p,int t)
    {
        int[] strg=new int[t+1];
        strg[0]=0;
        for(int i=0;i<wt.length;i++)
        {
            for(int j=1;j<strg.length;j++)
            {
                if(j-wt[i]>=0)
                {
                    int fact=strg[j-wt[i]]+p[i];
                    if(fact>strg[j])
                    {
                        strg[j]=fact;
                    }
                }

            }
        }
        System.out.println(strg[t]);

    }
    public static void main(String[] args)
    {
        int[] wt={1,5,3,4,2};
        int[] price={15,14,10,45,30};
        int t=7;
        solve(wt,price,t);
        knapsackub(wt,price,t);
        knapsackcomb(wt,price,t);
    }

}