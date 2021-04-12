import java.util.*;

public class pat
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n;
        System.out.print("enter the number");
        n=scn.nextInt();
        for(int i=0;i<n;i++)
        {
            int val=1;
            for(int j=0;j<=i;j++)
            {
                System.out.print(val+ "\t");
                val=val*(i-j)/(j+1);
            }
            System.out.println();
        }
    }
}