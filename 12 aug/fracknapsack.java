import java.util.*;

public class fracknapsack
{
    static class item implements Comparable<item>
    {
        int w;
        int p;
        double frac;

        item(int w,int p)
        {
            this.w=w;
            this.p=p;
            this.frac=(p*1.0)/w;
        }

        public int compareTo(item other)
        {
            if(this.frac>other.frac)
             return 1;
            else if(this.frac==other.frac)
             return 0;
            else 
             return -1;
        }
    }
    public static void solve(int[] w,int[] p,int t)
    {
        item[] objects=new item[w.length];
        for(int i=0;i<w.length;i++)
        {
            objects[i]=new item(w[i],p[i]);
        }
        Arrays.sort(objects);
        double tp=0;
        for(int i=objects.length-1;i>=0;i--)
        {
            if(t==0)
             break;
            else if(objects[i].w<=t)
            {
                tp=tp+objects[i].p;
                t=t-objects[i].w;
            }
            else 
            {
                double val=(t*1.0)/objects[i].w;
                tp=tp+(val*objects[i].p);
                t=0;
            }
             
        }
        System.out.println(tp);

    }
    public static void main(String[] args)
    {
        int[] w={10,40,20,30};
        int[] p={60,40,100,120};
        int t=50;
        solve(w,p,t);
    }
}