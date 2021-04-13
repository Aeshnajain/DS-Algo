import java.util.*;

public class crypto
{
    public static String unique(boolean[] dup)
    {
        String ans="";
        for(char ch:s1.toCharArray())
        {
            if(dup[ch-97]==false)
            {
               ans+=ch;
               dup[ch-97]=true;
            }
        }
        for(char ch:s2.toCharArray())
        {
            if(dup[ch-97]==false)
            {
               ans+=ch;
               dup[ch-97]=true;
            }
        }
        for(char ch:s3.toCharArray())
        {
            if(dup[ch-97]==false)
            {
               ans+=ch;
               dup[ch-97]=true;
            }
        }

        return ans;
    }

    public static int getnum(String s,int[] arr)
    {
        int sum=0;
        int pv=1;
        for(int i=s.length()-1;i>=0;i--)
        {
            char ch=s.charAt(i);
            sum+=arr[ch-97]*pv;
            pv=pv*10;

        }
        return sum;
    }

    public static void getans(int[] arr,boolean[] num,String ans)
    {
        if(ans.length()==0)
        {
            int n1=getnum(s1,arr);
            int n2=getnum(s2,arr);
            int n3=getnum(s3,arr);
            if(n1+n2==n3)
            {
                System.out.print((counter++)+".");
                for(int i=0;i<26;i++)
                {
                    if(arr[i]!=-1)
                    {
                      System.out.print((char)(i+97)+"="+arr[i]+" ");
                    }
                }
                System.out.println();
            }
            return;
        }
        char ch=ans.charAt(0);
        String ros=ans.substring(1,ans.length());
        for(int i=0;i<=9;i++)
        {
            if(num[i]==false)
            {
                arr[ch-97]=i;
                num[i]=true;
                getans(arr,num,ros);
                arr[ch-97]=-1;
                num[i]=false;
            }

        }
    }
    static int counter=1;
    static String s1,s2,s3;
    public static void main(String[] args)
    { 
        Scanner scn=new Scanner(System.in);
        s1=scn.next();
        s2=scn.next();
        s3=scn.next();
        boolean[] duplicate=new boolean[26];

        String ans=unique(duplicate);
       // System.out.print(ans);
       int[] arr=new int[26];
       Arrays.fill(arr,-1);

       boolean[] num=new boolean[10];
         getans(arr,num,ans);


        




    }
}