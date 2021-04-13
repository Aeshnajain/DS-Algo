import java.util.*;

public class catalan
{
    public static void catalan(int c)
    {
        int[] strg=new int[c+1];
        strg[0]=1;
        strg[1]=1;
        for(int i=2;i<=c;i++)
        {
           int left=0;
           int right=i-1;
           while(left<i && right>=0)
           {
               strg[i]+=strg[left]*strg[right];
               left++;
               right--;
           }
        }
        System.out.println(strg[c]);
    }
    public static void main(String[] args)
    {
        catalan(4);
    }
}