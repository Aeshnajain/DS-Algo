import java.util.*;

public class knightstour
{
    static int counter=1;
    public static void kt(int[][] arr,int cr,int cc,int move)
    {
        if(cr<0 || cc<0 || cr>=arr.length || cc>=arr.length || arr[cr][cc]!=0)
        {
            return;
        }
        else if(move==arr.length*arr.length)
        {
            arr[cr][cc]=move;
            System.out.println(counter++);
            for(int i=0;i<arr.length;i++)
            {
                for(int j=0;j<arr.length;j++)
                {
                    System.out.print(arr[i][j]+" ");
                }
                System.out.println();
            }
            arr[cr][cc]=0;
            return;
        }
        arr[cr][cc]=move;
        kt(arr,cr-2,cc+1,move+1);
        kt(arr,cr-2,cc-1,move+1);
        kt(arr,cr-1,cc+2,move+1);
        kt(arr,cr+1,cc+2,move+1);
        kt(arr,cr+2,cc+1,move+1);
        kt(arr,cr+2,cc-1,move+1);
        kt(arr,cr-1,cc-2,move+1);
        kt(arr,cr+1,cc-2,move+1);
        arr[cr][cc]=0;
        
    }
    public static void main(String[] args)
    {
        int[][] arr=new int[5][5];
        kt(arr,1,3,1);
    }
}