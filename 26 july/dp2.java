import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class dp2
{
    public static void solve(int[][] local)
    {
        int[][] global=new int[local.length][local[0].length];
        
    
        for(int i=global.length-1;i>=0;i--)
        {
            for(int j=global[0].length-1;j>=0;j--)
            {
                if(i==global.length-1 && j==global[0].length-1)
                {
                    global[i][j]=local[i][j];
                }
                else if(i==global.length-1)
                {
                    global[i][j]=local[i][j]+global[i][j+1];
                }
                else if(j==global[0].length-1)
                {
                    global[i][j]=local[i][j]+global[i+1][j];
                }
                else
                {
                    global[i][j]=local[i][j]+Math.min(global[i][j+1],global[i+1][j]);
                }
            }
        
        }
        System.out.println(global[0][0]+" ");

        pap(global,0,0,"");
    }

    public static void pap(int[][] global,int r,int c,String psf)
    {
        if(r==global.length-1 && c==global.length-1)
        {
            System.out.println(psf);
            return;
        }
        else if(r==global.length-1)
        {
              pap(global,r,c+1,psf+"h");
        }
        else if( c==global[0].length-1)
        {
            pap(global,r+1,c,psf+"v");
        }
        else 
        {
            if(global[r+1][c]>=global[r][c+1])
             pap(global,r,c+1,psf+"h");
            if(global[r+1][c]<=global[r][c+1])
              pap(global,r+1,c,psf+"v");

        }
        
    }
    public static void main(String[] args)
    {
        int[][] local={
            {1,5,1,0,3},
            {1,4,0,2,3},
            {4,0,1,3,2},
            {2,4,0,4,1},
            {1,2,3,2,0},
            
            
            
        };

        solve(local);
    }
}