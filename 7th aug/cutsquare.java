import java.util.*;

public class cutsquare
{
    static int ans=Integer.MAX_VALUE;
    public static int solve(int l,int b,int[][] strg)
    {
        if(l==0 || b==0)
         return 0;
        else if(l==b)
         return 1;
        else if(strg[l][b]!=0)
         return strg[l][b];
        else 
        {
            for(int x=1;x<=Math.min(l,b);x++)
            {
                int lhl=l-x;
                int lhb=b;
                int lha=solve(lhl,lhb,strg);
                int rhl=x;
                int rhb=b-x;
                int rha=solve(rhl,rhb,strg);
                int tha=lha+rha;

                int lvl=l-x;
                int lvb=x;
                int lva=solve(lvl,lvb,strg);
                int rvl=l;
                int rvb=b-x;
                int rva=solve(rvl,rvb,strg);
                int tva=lva+rva;
                int min=tva>tha?tha:tva;
                ans=ans>min?min:ans;
                

            }
            //ans++;
            strg[l][b]=ans+=1;
            return ans;
            
        }
        
        
    }
    public static void main(String[] args)
    {
        int l=36;
        int b=30;
        int[][] strg=new int[l+1][b+1];
        int ans=solve(l,b,strg);
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                System.out.print(strg[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println(ans);
    }
}