import java.util.*;

public class trains
{
    public static void solve(int[] arr,int[] dep)
    {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i=0;
        int j=0;
        int c=0;
        int max=Integer.MIN_VALUE;
        while(i<arr.length && j<dep.length)
        {
            if(arr[i]<=dep[j])
            {
                c++;
                i++;
            }
            else
            {
                c--;
                j++;
            }
            if(c>=max)
             max=c;

        }
        System.out.println(max);
    }
    public static void main(String[] args)
    {
        int[] arr={900,940,950,1100,1500,1800};
        int[] dep={910,1200,1120,1130,1900,2000};
        solve(arr,dep);
    }
}
