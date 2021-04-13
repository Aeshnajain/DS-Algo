import java.util.*;

public class uprec
{

  static String[] codes=
  { 
    ".",
    "abc",
    "def",
    "ghi",
    "jklm",
    "no",
    "pqrs",
    "tu",
    "vwxy",
    "z"
   };

    public static void subseq(String q,String asf)
    {
        if(q.length()==0)
        {
            System.out.println(asf);
            return;
        }
        char ch=q.charAt(0);
        String nq=q.substring(1,q.length());

        subseq(nq,ch+asf);
        subseq(nq,'-'+asf);
    }
    //print stair path1
    public static void psp1(int src,String asf)
    {
        if(src==0)
        {
            System.out.println(asf);
            return;
        }
    
        for(int i=1;i<=3;i++)
        {
            if(src-i>=0)
           { 
               psp1(src-i,i+asf);
           }
        }


    }
    //keypad combination
    public static void kpc(String ques,String asf)
    {
        if(ques.length()==0)
        {
            System.out.println(asf);
            return;
        }
        char ch=ques.charAt(0);
        String rques=ques.substring(1,ques.length());
        String chcode=codes[ch-48];
        for(int i=0;i<chcode.length();i++)
        {
            kpc(rques,asf+chcode.charAt(i));
        }


    }
    //print stair path2
    public static void psp2(int[] stairs,int src,String psf)
    {
        if(src==stairs.length-1)
        {
            System.out.println(psf);
            return;
        }
        int x=stairs[src];
        for(int i=1;i<=x;i++)
        {
            if(src+i<stairs.length)
            {
                psp2(stairs,src+i,psf+i);
            }
        }
    }

    public static void maze(int sr,int sc,int dr,int dc,String asf)
    {
        if(sr==dr && sc==dc)
        {
            System.out.println(asf);
            return;

        }
        if(sr<dr)
        {
            maze(sr+1,sc,dr,dc,'v'+asf);
        }
        if(sc<dc)
        {
            maze(sr,sc+1,dr,dc,'h'+asf);
        }
    }

    public static void multimaze(int sr,int sc,int dr,int dc,String asf )
    {
        if(sr==dr && sc==dc)
        {
            System.out.println(asf);
            return;
        }
         
         if(sr<dr)
         {
             for(int i=1;i<=dr;i++)
            {
                if(sr+i<=dr)
                {
                 multimaze(sr+i,sc,dr,dc,asf+'h'+i);
                }
            }
         }
        if(sc<dc)
         {
             for(int i=1;i<=dc;i++)
            {
                if(sc+i<=dc)
                {
                 multimaze(sr,sc+i,dr,dc,asf+'v'+i);
                }
            }
         } 
        if(sr<dr && sc<dc )
         {
             for(int i=1;i<=dr && i<=dc;i++)
            {
                if(sr+i<=dr && sc+i<=dc)
                {
                 multimaze(sr+i,sc+i,dr,dc,asf+'d'+i);
                }
            }
         } 
    }
    
    
    public static void main(String[] args)
    {
        String s="abc";
        subseq(s,"");

        psp1(7,"");

        kpc("835","");

        int[] arr={3,2,0,4,1,2,0,2,3,0,1};
        psp2(arr,0,"");

        maze(0,0,2,2,"");

        multimaze(0,0,2,2,"");
    }
}