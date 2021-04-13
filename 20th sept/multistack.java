import java.util.*;

public class multistack
{
    private int[] da;
    private int[] na;
    private int[] ta;
    int free;

    multistack(int k,int capacity)
    {
        da=new int[capacity];
        na=new int[capacity];
        ta=new int[k];
        free=0;
        for(int i=0;i<na.length;i++)
        {
            if(i==na.length-1)
            {
                na[i]=-1;
            }
            na[i]=i+1;

        }
        for(int i=0;i<ta.length;i++)
        {
            ta[i]=-1;

        }
    }

    void push(int i,int val)
    {
        if(isfull())
        {
            System.out.println("stack overflow");
            return;
        }
        int temp=free;
        free=na[free];
        na[temp]=-1;

        na[temp]=ta[i];
        ta[i]=temp;
        da[temp]=val;

    }

    void pop(int i)
    {
        if(isempty(i))
        {
            System.out.println("stack underflow");
            return;
        }

        int temp=ta[i];
        ta[i]=na[temp];
        na[temp]=-1;

        da[temp]=0;
        na[temp]=free;
        free=temp;


    }
    int top(int i)
    {
        if(isempty(i))
        {
            System.out.println("stack underflow");
            return -1;
        }
        return da[ta[i]];
        
    }

    boolean isempty(int i)
    {
        return ta[i]==-1;
    }
    boolean isfull()
    {
        return free==-1;
    }


    public static void main(String[] args)
    {
        multistack ms=new multistack(4,12);
        ms.push(0,10);
        ms.push(1,20);
        ms.push(2,30);
        ms.pop(1);
        ms.push(3,40);
        ms.push(3,50);
        ms.pop(3);
        ms.push(2,70);
        ms.push(1,90);
        ms.push(0,100);
        for(int i=0;i<4;i++)
        {
            System.out.print(i+" : ");
            while(!ms.isempty(i))
            {
                System.out.print(" " + ms.top(i)+" ");
                ms.pop(i);
            }
            System.out.println();
        }
    }
}