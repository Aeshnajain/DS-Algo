import java.util.*;

public class lps2
{
    public static void solve(String s)
    {
        int[][] strg=new int[s.length()][s.length()];
        for(int g=0;g<strg.length;g++)
        {
            for(int i=0;i<strg.length-g;i++)
            {
                int j=i+g;
                if(g==0)
                {
                    strg[i][j]=1;
                }
                else if(g==1)
                {
                    strg[i][j]=s.charAt(i)==s.charAt(j)?2:1;
                }
                else
                {
                    if(s.charAt(i)==s.charAt(j))
                    {
                        strg[i][j]=strg[i+1][j-1]+2;
                    }
                    else
                    {
                        strg[i][j]=Math.max(strg[i][j-1],strg[i+1][j]);
                    }
                }

            }
        } 
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                System.out.print(strg[i][j]+" ");
            }
            System.out.println();
            
        }
        System.out.println(strg[0][strg[0].length-1]);

    }
    public static void main(String[] args)
    {
        solve("abckycbc");
    }
}