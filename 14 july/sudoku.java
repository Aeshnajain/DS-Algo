import java.util.*;

public class sudoku
{
    public static boolean isvalid(int[][] ques,int r,int c,int option)
    {
        for(int i=0;i<ques.length;i++)
        {
            if(ques[i][c]==option)
            {
                return false;
            }
        }
        for(int i=0;i<ques.length;i++)
        {
            if(ques[r][i]==option)
            {
                return false;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                r=r/3*3+i;
                c=c/3*3+j;
                if(ques[r][c]==option)
                {
                    return false;
                }
            }
        }

        return true;
    }
    public static void sudoku(int[][] ques,int r,int c)
    {
        if(r==ques.length && c==0)
        {
            for(int i=0;i<ques.length;i++)
            {
                for(int j=0;j<ques.length;j++)
                {
                    System.out.print(ques[i][j]);
                }
                System.out.println();
            }

        }
        else if(c==ques[0].length-1)
        {
            if(ques[r][c]!=0)
            {
                sudoku(ques,r+1,0);
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    if(isvalid(ques,r,c,i)==true)
                    {
                        ques[r][c]=i;
                        sudoku(ques,r+1,0);
                        ques[r][c]=0;
                    }
                }
            }
        }

         else
         {
            if(ques[r][c]!=0)

            {
                sudoku(ques,r,c+1);
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    if(isvalid(ques,r,c,i)==true)
                    {
                        ques[r][c]=i;
                        sudoku(ques,r,c+1);
                        ques[r][c]=0;
                    }
                }

            }
        }
    }
    public static void main(String[] args)
    {
        int[][] ques={
            {3,0,6,5,0,8,4,0,0},
            {5,2,0,0,0,0,0,0,0},
            {0,8,7,0,0,0,0,3,1},
            {0,0,3,0,1,0,0,8,0},
            {9,0,0,8,6,3,0,0,5},
            {0,5,0,0,9,0,6,0,0},
            {1,3,0,0,0,0,2,5,0},
            {0,0,0,0,0,0,0,7,4},
            {0,0,5,2,0,6,3,0,0},
        };
        sudoku(ques,0,0);
    }
}