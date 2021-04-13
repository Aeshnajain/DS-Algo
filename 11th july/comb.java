import java.util.*;

public class comb
{
    public static void pc(int cb,int n,int bssf,int r,String asf)
    {
        if(bssf==r)
        {
            System.out.println(asf);
            return;
        }
        if(cb==n)
        {
            return;
        }
        pc(cb+1,n,bssf+1,r,asf+cb);
        pc(cb+1,n,bssf,r,asf);
        
    }
    public static void main(String[] args)
    {
        pc(0,4,0,2,"");
    }
}