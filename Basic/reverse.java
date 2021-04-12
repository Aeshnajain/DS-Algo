import java.util.*;

public class reverse
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the number");
        int n,j,m=0;
        n=scn.nextInt();
        for(int i=n;i!=0;i=i/10)
        {
            j=i%10;
            m=m*10+j;
        }
        System.out.println("reversed number is "+m);
    }
}