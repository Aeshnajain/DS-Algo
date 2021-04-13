import java.util.*;

public class binary
{

    public static void ans(int n)
    {
      int[] strg=new int[n+1];
      strg[0]=0;
      strg[1]=1;
      for(int i=2;i<strg.length;i++)
      {
        strg[i]=strg[i-1]+strg[i-2];
      }
      System.out.println(strg[n]+strg[n-1]);
    }
    public static void main(String[] args)
    {
       int n=4;
       ans(n);

    }
}