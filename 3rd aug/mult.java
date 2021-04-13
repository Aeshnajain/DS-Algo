import java.util.*;

public class mult
{
    public static void solve(String s,int t)
    {
        int[][] strg=new int[s.length()][t];
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                if(i==0)
                {
                    strg[0][0]=1;
                    int ch=(s.charAt(0)-48)%6;
                    strg[0][ch]=1;
                }
                else
                {
                    strg[i][j]+=strg[i-1][j];
                    int ch=s.charAt(i)-48;
                    int num=j*10+ch;
                    int r=num%6;
                    strg[i][r]=strg[i-1][j]+strg[i][r];
                }
            }
        }
        for(int i=0;i<strg.length;i++)
        {
            for(int j=0;j<strg[0].length;j++)
            {
                System.out.print(strg[i][j]+"\t ");
            }
            System.out.println();
        }
        System.out.println(strg[s.length()-1][0]);
    }
    public static void main(String[] args)
    {
        solve("235168",6);
    }
}