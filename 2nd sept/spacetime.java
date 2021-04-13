import java.util.*;

public class spacetime
{
    public static void func(int x,int n)
    {
        int sum=0;
        int pox=1;
        for(int i=n;i>=1;i--)
        {
            pox=pox*x;
            sum+=i*pox;
        }
        System.out.println(sum);
    }

    public static void soe(int val)
    {
        boolean[] arr=new boolean[val+1];
        Arrays.fill(arr,true);
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i*i<val;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i;j*i<val;j++)
                {
                    if(arr[i*j]==true)
                    {
                        arr[i*j]=false;
                    }

                }

            }

        }

        for(int i=0;i<val;i++)
        {
            if(arr[i]==true)
            {
                System.out.println(i);
            }

        }
    }



    public static int[] getspf(int val) 
    {
        int[] res=new int[val+1];
        boolean[] arr=new boolean[val+1];
        Arrays.fill(arr,true);
        for(int i=0;i<res.length;i++)
        {
            res[i]=i;
        }
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i*i<val;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i;j*i<val;j++)
                {
                    if(arr[i*j]==true)
                    {
                        arr[i*j]=false;
                        res[i*j]=i;
                    }

                }

            }

        }

        return res;

    }

    public static void primefact(int v,int[] spf)
    {
        System.out.print(v+"=");
        while(v>1)
        {
            System.out.print(spf[v]+"*");
            v=v/spf[v];
        }

        System.out.println();
    }

    public static void setabit(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));

        int mask=1<<k;
        System.out.println(mask+"="+Integer.toBinaryString(mask));

        x=x|mask;
        System.out.println(x+"="+Integer.toBinaryString(x));

    }

    public static void unsetabit(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));

        int mask=~(1<<k);
        System.out.println(mask+"="+Integer.toBinaryString(mask));

        x=x&mask;
        System.out.println(x+"="+Integer.toBinaryString(x));

    }

    public static void toggle(int x,int k)
    {
        System.out.println(x+"="+Integer.toBinaryString(x));

        int mask=1<<k;
        System.out.println(mask+"="+Integer.toBinaryString(mask));

        x=x^mask;
        System.out.println(x+"="+Integer.toBinaryString(x));
    }


    // public static int personcap(boolean[] arr,ArrayList<ArrayList> pcapmap,int p)
    // {
    //     for(int i=0;i<pcapmap.getAt(p).size();i++)
    //     {
    //         if(arr[i]==false)
    //         {
    //           arr[i]=true;
    //           personcap(arr,pcapmap,p+1);
    //         }
    //     }
    //     arr[i]=false;

    // }
    public static void main(String[] args)
    {
        int x=3;
        int n=56;
        //func(x,n);

        int val=30;
        soe(val);

        int[] spf=getspf(10000);
        primefact(50,spf);

        setabit(n,x);
        unsetabit(n,x);
        toggle(n,x);
        
        boolean[] arr=new boolean[x];

        //a party and cap ques is to be solved used bitmasking to reduce time taken.
        //int p=personcap(arr,pcapmap,0);



    }
}