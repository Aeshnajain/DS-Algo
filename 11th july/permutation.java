import java.util.*;

public class permutation
{
    public static void printperm(boolean[] boxes,int co,int to,String psf)
    {
        if(co>to)
        {
            System.out.println(psf);
            return;
        }
        for(int i=0;i<boxes.length;i++)
        {
            if(boxes[i]==false)
            {
                 boxes[i]=true;
              printperm(boxes,co+1,to,psf+"o["+co+"] box["+i+"] ");
                boxes[i]=false;
            }       
        }
        
       
       
    }
    public static void main(String[] args)
    {
        boolean[] boxes=new boolean[3];
        int objects=2;
        printperm(boxes,1,objects,"");
    }
}