import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class lpss2
{
    static int c=0;
    public static void solve(String s)
    {
        int length=0;
        boolean[][] strg=new boolean[s.length()][s.length()];
        for(int g=0;g<strg.length;g++)
        {
            for(int i=0;i<strg.length-g;i++)
            {
                int j=i+g;
                if(g==0)
                {
                    strg[i][j]=true;
                    c++;
                }
                else if(g==1)
                {
                    strg[i][j]=s.charAt(i)==s.charAt(j)?true:false;
                    if(strg[i][j])
                     c++;
                }
                else
                {
                    if(s.charAt(i)==s.charAt(j) && strg[i+1][j-1]==true)
                    {
                        strg[i][j]=true;
                        c++;
                    }
                    else
                    {
                        strg[i][j]=false;
                    }
                }
                if(strg[i][j])
                 length=g+1;
            }
        
        }
        System.out.println(c+" "+length);
        

    }
    public static void main(String[] args)
    {
        solve("abccbc");
    }
}