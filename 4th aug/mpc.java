import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class mpc
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
                 strg[i][j]=0;
                else if(g==1)
                 strg[i][j]=s.charAt(i)==s.charAt(j)?0:1;
                else
                {
                    int min=88;
                    if(s.charAt(i)==s.charAt(j) && strg[i+1][j-1]==0)
                    {
                        strg[i][j]=0;
                    }
                    else{
                        for(int m=j-g,n=i+1;m<j && n<=i+g;m++,n++)
                    {
                        int ans=strg[i][m]+strg[n][j];
                        if(ans<min)
                        {
                            min=ans;
                        }
                    }
                    strg[i][j]=min+1;

                    }
                    
                    
                    
                }
    
            }
        }
        System.out.println(strg[0][s.length()-1]);

    }
    public static void main(String[] args)
    {
        solve("abccbc");
    }
}