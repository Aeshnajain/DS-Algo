import java.util.*;

public class pat2
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n;
        System.out.print("enter the number");
        n=scn.nextInt();
        int val=1;
        int space=n/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=space;j++)
            {
                System.out.print(" ");
            }
            for(int m=1;m<=val;m++)
            {
                System.out.print("1");
            }
            if(i<=n/2)
            {
                val+=2;
                space--;
            }
            else
            {
                val-=2;
                space++;
            }
            System.out.println();
        }

    }
}