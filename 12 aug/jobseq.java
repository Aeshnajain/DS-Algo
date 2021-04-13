import java.util.*;

public class jobseq
{
    static class job implements Comparable<job>
    {
        char n;
        int l;
        int p;

        job(char n,int l,int p)
        {
            this.n=n;
            this.l=l;
            this.p=p;
        }

        public int compareTo(job other)
        {
            return this.p-other.p;
        }
    }
    public static void solve(char[] name,int[] l,int[] prof)
    {
        int max=0;
        for(int i=0;i<l.length;i++)
        {
            if(l[i]>max)
             max=l[i];
        }
        char[] strg=new char[max+1]; 
        job[] task=new job[name.length];
        for(int i=0;i<task.length;i++)
        {
            task[i]=new job(name[i],l[i],prof[i]);
        }
        Arrays.sort(task);
        int mp=0;
        for(int i=task.length-1;i>=0;i--)
        {
            if(task[i].l<=strg.length-1)
            {
                for(int j=task[i].l;j>0;j--)
                {
                    if(strg[j]=='\0')
                    {
                      strg[j]=task[i].n;
                      mp=mp+task[i].p;
                      break;
                    }
                }
            }
             
        }
        for(int i=0;i<strg.length;i++)
        {
            System.out.println(strg[i]);
        }
        System.out.println(mp);
    }

    public static void main(String[] args)
    {
        char[] name={'a','b','c','d','e'};
        int[] l={2,1,2,1,3};
        int[] prof={100,19,27,25,15};
        solve(name,l,prof);
    }
}