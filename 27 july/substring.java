import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class substring
{
    public static void solve(String s)
    {
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch=='a')
            {
                a=1+2*a;
            }
            else if(ch=='b')
            {
                b=a+2*b;
            }
            else
            {
                c=b+2*c;
            }

        }
        System.out.println(c);
    }
    public static void main(String[] args)
    {
        solve("abcabc");
        
    }
}