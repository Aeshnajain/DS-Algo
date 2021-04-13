import java.util.*;

public class encodingsdp
{
    public static void solve(int[] q)
    {
        int[] strg=new int[q.length];
        if(q[q.length-1]!=0)
            {
               strg[strg.length-1]=1;
            }

        
        for(int i=strg.length-2;i>=0;i--)
        {
            int num=q[i]*10+q[i+1];
            if(q[i]==0)
            {
                strg[i]=0;
            }
            else if(num<=26 && num>=10 && i==strg.length-2)
            {
                strg[i]=strg[i+1]+1;

            }
            else if(num<=26 && num>=10 && i!=strg.length-2)
            {
                strg[i]=strg[i+1]+strg[i+2];
            }
            else
            {
                strg[i]=strg[i+1];
            }
        
            
        }
        System.out.println(strg[0]);

    }
    public static void main(String[] args)
    {
        int[] ques={1,2,1,3,2,6,1,2,0,1,4};
        solve(ques);
    }
}