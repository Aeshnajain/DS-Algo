import java.util.*;

public class rep
{
    public static void main(String[] args)
    {
        int[] arr={4,2,0,1,2,0};
        int m=0;
        int i=0;
        
        while(i<arr.length && m<arr.length)
        {
            if(arr[i]==m)
            {
                arr[i]='*';
                m++;
                i=0;
            }
            else
            {
                if(i!=(arr.length-1))
                {
                    i++;
                }
                else
                {
                    m++;
                    i=0;
                }
                
            }
        }
        for(int j=0;j<arr.length;j++)
        {
            if(arr[j]!='*')
            {
                System.out.println("repeated value is "+arr[j]);
            }
        }

    }
}