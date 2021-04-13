import java.util.*;

public class perm
{
    public static void pp(int cb,int n,int isf,int r,String asf,boolean[] items)
    {
        if(cb==n)
        {
            if(isf==r)
            {
                System.out.println(asf);
                return;
            }
            return;

        }
        pp(cb+1,n,isf,r,asf,items);
        for(int i=0;i<items.length;i++)
        {
            if(items[i]==false)
            {
                items[i]=true;
                pp(cb+1,n,isf+1,r,asf+i+cb+" ",items);
                items[i]=false;
            }
        }
        
        
    }
    public static void main(String[] args)
    {
        int n=4;
        int r=2;
        pp(0,n,0,r,"",new boolean[r]);
    }
}