import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class lpss
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
                    if(s.charAt(i)==s.charAt(j) && strg[i+1][j-1]==g-1)
                    {
                        strg[i][j]=strg[i+1][j-1]+2;
                    }
                    else
                    {
                        strg[i][j]=Math.max(strg[i+1][j],strg[i][j-1]);
                    }
                }
            }
        }
        System.out.println(strg[0][strg.length-1]);
    }
    public static void main(String[] args)
    {
        solve("abccbc");
    }
}