import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class lcs
{
    public static void solve(String s1,String s2)
    {
        int[][] strg=new int[s1.length()+1][s2.length()+1];
        
        for(int i=strg.length-1;i>=0;i--)
        {
            for(int j=strg[0].length-1;j>=0;j--)
            {
                if(i==strg.length-1 || j==strg[0].length-1)
                {
                    strg[i][j]=0;
                }
                else if(s1.charAt(i)==s2.charAt(j))
                {
                    strg[i][j]=strg[i+1][j+1]+1;
                }
                else
                {
                    strg[i][j]=strg[i+1][j]>strg[i][j+1]?strg[i+1][j]:strg[i][j+1];
                }
            }
        }

        System.out.println(strg[0][0]);
    }
    public static void main(String[] args)
    {
        solve("abcd","abed");
    }
}
