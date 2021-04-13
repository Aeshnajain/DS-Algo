import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class a {

    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        int r=scn.nextInt();
        int c=scn.nextInt();
        int[][] arr=new int[r][c];
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                arr[i][j]=scn.nextInt();
            }
        }
        int counter=0;
        int minr=0;
        int minc=0;
        int maxr=arr.length-1;
        int maxc=arr[0].length-1;
         
        System.out.println();
        
        while(counter<arr.length*arr[0].length)
        {
            for(int i=minr;i<=maxr;i++)
            {
                System.out.print(arr[i][minc]+" ");
                counter++;
            }
            minc++;
            for(int j=minc;j<=maxc;j++)
            {
                System.out.print(arr[maxr][j]+" ");
                counter++;
            }
            maxr--;
            for(int i=maxr;i>=minr;i--)
            {
                System.out.print(arr[i][maxc]+" ");
                counter++;
            }
            maxc--;
            for(int j=maxc;j>=minc;j--)
            {
               System.out.print(arr[minr][j]+" "); 
                counter++;
            }
            minr++;
            
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}