import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class a {
    
    static int min=1000;
    
    public static void solve(int[][] arr,int sr,int sc,int dr,int dc,int c)
    {
        if(sr<0 || sr>=arr.length || sc<0 || sc>=arr.length || arr[sr][sc]==1)
        {
            return;
        }
        if(sr==dr && sc==dc)
        {
            c++;
            if(c<min)
            {
                c=min;
                
            }
            return;
            
        }
        arr[sr][sc]=1;
        solve(arr,sr+2,sc+1,dr,dc,c+1);
        solve(arr,sr+2,sc-1,dr,dc,c+1);
        solve(arr,sr+1,sc+2,dr,dc,c+1);
        solve(arr,sr+1,sc-2,dr,dc,c+1);
        solve(arr,sr-2,sc+1,dr,dc,c+1);
        solve(arr,sr-2,sc-1,dr,dc,c+1);
        solve(arr,sr-1,sc+2,dr,dc,c+1);
        solve(arr,sr-1,sc-2,dr,dc,c+1);
        arr[sr][sc]=0;
    }

    public static void main(String[] args) {
        
        Scanner scn=new Scanner(System.in);
        int[][] arr=new int[21][21];
        
        solve(arr,5,7,15,20,0);
        System.out.print(min);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}