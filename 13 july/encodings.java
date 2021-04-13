import java.util.*;

public class encodings
{
    public static void getans(String ques,String asf,String s)
    {
        if(ques.length()==0)
        {
            System.out.println(asf);
            return;
        }
        else if(ques.length()==0 && ques.charAt(0)!=0)
        {
            int n=ques.charAt(0)-48;
            String rques=ques.substring(1,ques.length());
            getans(rques,asf+s.charAt(n),s);
            
        }
        else
        {
            if(ques.charAt(0)!=0)
            {
                int n=ques.charAt(0)-48;
              String rques=ques.substring(1,ques.length());
               getans(rques,asf+s.charAt(n),s);
            }
            int x=ques.charAt(0)-48;
            int y=ques.charAt(1)-48;
            int num=x*10+y;
            if(num>=10 && num<=26)
            {
                String rques=ques.substring(2,ques.length());
                getans(rques,asf+s.charAt(num),s);
            }
        }
    }
    public static void main(String[] args)
    {
    
        String s="-abcdefghijklmnopqrstuvwxyz";
        getans("1123","",s);
    }
}