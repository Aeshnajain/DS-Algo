import java.util.*;

public class chocwrap
{
    public static void choc(int a,int p,int w,int wsf,int e)
    {
        if(wsf<w && a<p)
        {
            System.out.print(e);
            return;
        }
        
        int c=a/p;
        a=a%p;
        c=c+(wsf/w);
        int nwsf=c+(wsf%w);
    
        choc(a,2,2,nwsf,e+c);
    }
    public static void main(String[] args)
    {
        choc(10,2,2,0,0);
    }
}