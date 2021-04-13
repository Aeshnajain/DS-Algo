import java.util.*;

public class activities
{
    static class interval implements Comparable<interval>
    {
        int start;
        int end;

        interval(int start,int end)
        {
            this.start=start;
            this.end=end;
        }

        public int compareTo(interval other)
        {
            return this.end-other.end;
        }
    }
    // public static void solve(int[] s,int[] e)
    // {
    //     interval[] act=new interval[s.length];
    //     for(int i=0;i<s.length;i++)
    //     {
    //         act[i]=new interval(s[i],e[i]);
    //     }
    //     Arrays.sort(act);
    //     int[] strg=new int[s.length];
    //     strg[0]=1;
    //     for(int i=1;i<strg.length;i++)
    //     {
    //         int max=0;
    //         for(int j=i-1;j>=0;j--)
    //         {
    //             if(act[i].start>act[j].end)
    //             {
    //                 if(strg[j]>max)
    //                  max=strg[j];
    //             }
    //             strg[i]=max+1;
    //         }
            
    //     }
    //     System.out.println(strg[s.length-1]);
        

    // }
    
    public static void solve(int[] s,int[] e)
    {
        interval[] act=new interval[s.length];
        for(int i=0;i<s.length;i++)
        {
            act[i]=new interval(s[i],e[i]);
        }
        Arrays.sort(act);
        int last=0;
        int count=1;
        for(int i=1;i<s.length;i++)
        {
            if(act[i].start>act[last].end)
            {
                count++;
                last=i;
            }
        }
        System.out.println(count);


    }


    public static void main(String[] args)
    {
        int[] start={12,2,6,7,9,3,3};
        int[] end={14,5,8,10,11,4,7};
        solve(start,end);
    }
}