import java.util.*;
//rotated shell printing
public class sp
{
    public static void main(String[] args)
    {
        int[][] arr={
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
        };
        Scanner scn=new Scanner(System.in);
        System.out.print("enter the number of shell and rotations");
        int s=scn.nextInt();
        int n=scn.nextInt();
        int minr=0+s-1;
        int minc=0+s-1;
        int maxr=arr.length-s;
        int maxc=arr[0].length-s;
        int[] a=new int[(maxr*maxc)];
        int count=0;
        for(int i=minr;i<maxr;i++ )
        {
           a[count]=arr[i][minc];
           count++;
        }
        for(int j=minc;j<maxc;j++)
        {
            a[count]=arr[maxr][j];
            count++;
        }
        for(int i=maxr;i>minr;i--)
        {
            a[count]=arr[i][maxc];
            count++;
        }
        for(int j=maxc;j>minc;j--)
        {
            a[count]=arr[minr][j];
            count++;
        }
        
        for(int i=(count-n);i<count;i++)
        {
           
             System.out.print(a[i]+" ");
           
        }
        for(int i=0;i<(count-n);i++)
       {
            System.out.print(a[i]+" ");
        }
       

    }

}