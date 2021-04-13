import java.util.*;

public class distsubseq{

    public static void solve(String s)
    {
        int[] strg=new int[s.length()+1];
        strg[0]=2;
        for(int i=1;i<strg.length-1;i++)
        {
            int m=strg.length-1;
            for(int j=i-1;j>=0;j--)
            {
                if(s.charAt(i)==s.charAt(j))
                {
                    m=j;
                    break;
                }
            }
            strg[i]=m==0?2*strg[i-1]-1:2*strg[i-1]-strg[m-1];
             
        }
        
        System.out.println(strg[s.length()-1]);

    }
    public static void main(String[] args)
    {
        solve("ababcdbd");
    }
}