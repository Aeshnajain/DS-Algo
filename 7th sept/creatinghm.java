import java.util.*;

public class creatinghm<k,v>
{
    class pair
    {
        k key;
        v value;

        pair(k key,v value)
        {
            this.key=key;
            this.value=value;
        }
    }

    private LinkedList<pair>[] buckets;
    int size=0;
    public creatinghm(){
        buckets=new LinkedList[4];
        for(int i=0;i<buckets.length;i++)
        {
            buckets[i]=new LinkedList<>();
        }
    }
    public boolean containsKey(k key)
    {
        int bi=hashfunc(key);
        int di=findwithbi(key,bi);

        if(di==-1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    public v get(k key)
    {
        int bi=hashfunc(key);
        int di=findwithbi(key,bi);

        if(di==-1)
        {
            return null;
        }
        else
        {
            pair p2u=buckets[bi].get(di);
            return p2u.value;
        }

    }

    public v remove(k key)
    {
        int bi=hashfunc(key);
        int di=findwithbi(key,bi);

        if(di==-1)
        {
            return null;
        }
        else
        {
            pair p2u=buckets[bi].remove(di);
            size--;
            return p2u.value;
        }

    }

    public void display()
    {
        for(int i=0;i<buckets.length;i++)
        {
            System.out.print("buckets"+i+":"+" ");
            for(pair p:buckets[i])
            {
                System.out.print("["+p.key+"->"+p.value+"]");

            }
            System.out.println();

        }
    }

    public void put(k key,v value)
    {
        int bi=hashfunc(key);
        int di=findwithbi(key,bi);

        if(di==-1)
        {
            pair p2a=new pair(key,value);
            buckets[bi].add(p2a);
            size++;
        }
        else
        {
            pair p2u=buckets[bi].get(di);
            p2u.value=value;
        }

        double lambda=(size*1.0)/buckets.length;
        if(lambda>2)
        {
            rehash();
        }

    }

    public ArrayList<k> keyset()
    {
        ArrayList<k> keys=new ArrayList<>();
        for(int bi=0;bi<buckets.length;bi++)
        {
            for(pair p:buckets[bi])
            {
                keys.add(p.key);

            }
        }

        return keys;

    }

    private int hashfunc(k key)
    {
        int i=key.hashCode();
        int bi=Math.abs(i)%buckets.length;
        return bi;
    }

    private int findwithbi(k key,int bi)
    {
        for(int i=0;i<buckets[bi].size();i++)
        {
            if(buckets[bi].get(i).equals(key))
            {
                return i;
            }
        }

         return -1;
    }

    private void rehash()
    {
        LinkedList<pair>[] obuckets=buckets;
        buckets=new LinkedList[buckets.length*2];

        for(int i=0;i<buckets.length;i++)
        {
            buckets[i]=new LinkedList<>();
        }
        size=0;

        for(int bi=0;bi<obuckets.length;bi++)
        {
            for(pair p:obuckets[bi])
            {
                put(p.key,p.value);

            }
        }
        
        

        

    }


}