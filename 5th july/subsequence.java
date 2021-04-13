import java.util.*;

public class subsequence
{
    public static ArrayList<String> getss(String s)
    {
        if(s.length()==0)
        {
            ArrayList<String> bres=new ArrayList<>();
            bres.add("");
            return bres;
        }
        char ch= s.charAt(0);
        String ros=s.substring(1,s.length());
        ArrayList<String> rres=getss(ros);
        ArrayList<String> mres=new ArrayList<>();
        for(int i=0;i<rres.size();i++)
        {
            String rstr=rres.get(i);
            mres.add(ch + rstr);
            mres.add('-'+ rstr);
        }
        return mres;
    }


    // public static ArrayList<String> getsa(String s)
    // {
    //     if(s.length()==0)
    //     {
    //         ArrayList<String> base=new ArrayList<>();
    //         return base;
    //     }
    //     char ch=s.charAt(0);
    //     String ros=s.substring(1,s.length());
    //     ArrayList<String> rans=getsa(ros);
    //     ArrayList<String> ans=new ArrayList<>();
    //     String base= ch + '-';
    //     for(int i=0;i<ros.length();i++)
    //     {
    //         base=base + '-';
    //     }
    //     ans.add(base);
    //     for(int i=0;i<rans.size();i++)
    //     {
    //         String m=rans.get(i);
    //         if(m.charAt(0)!='-')
    //         {
                
    //             ans.add(ch+m);
               
    //         }
            
            
    //             ans.add('-'+m);
        
    //     }

    //     return ans;
    // }
    public static void main(String[] args)
    {
        ArrayList<String> list=getss("abcd");
        System.out.println(list);

        // ArrayList<String> nlist=getsa("abcd");
        // System.out.println(nlist);

    }
}