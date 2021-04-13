import java.util.*;

public class lpsalg
{
    public static int[] getlps(String pat)
    {
        int[] lps=new int[pat.length()];
        int i=1;
        int j=0;
        lps[0]=0;

        while(i<pat.length())
        {
            if(pat.charAt(i)==pat.charAt(j))
            {
                lps[i]=j+1;
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
        }
        return lps;

    }
    public static void kmp(String src,String pat)
    {
        int[] lps=getlps(pat);
        int i=0;
        int j=0;

        while(i<src.length())
        {
            if(src.charAt(i)==pat.charAt(j))
            {
                i++;
                j++;
               if(j==pat.length())
              {
                System.out.println("found at"+" "+(i-pat.length()));
                j=lps[j-1];
              }
            }
            
            else
            {
                if(j!=0)
                 j=lps[j-1];
                else 
                {
                    i++;
                }


            }
        }
    }
    public static void main(String[] args)
    {
        kmp("hk","vavhdksfjbjhdbkjshhfvhbdjk");
    }
}