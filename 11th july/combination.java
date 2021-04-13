import java.util.*;

public class combination
{
    public static void printperm(boolean[] boxes,int co,int to,String psf,int start)
    {
        if(co>to)
        {
            System.out.println(psf);
            return;
        }
        for(int i=start;i<boxes.length;i++)
        {
            
                 start++;
              printperm(boxes,co+1,to,psf+"o["+co+"] box["+i+"] ",start);
                
                  
        }
        
       
       
    }
    public static void main(String[] args)
    {
        boolean[] boxes=new boolean[4];
        int objects=2;
        printperm(boxes,1,objects,"",0);
    }
}