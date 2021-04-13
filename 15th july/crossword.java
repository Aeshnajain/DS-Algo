import java.util.*;

public class crossword
{
    public static boolean cpv(int[][] puzzle,int r,int c,String word)
    {
        for(int i)

    }
    public static void solve(int[][] puzzle,String words,int idx)
    {
        if(idx==words.length())
        {
            return;
        }
        String word=words[idx];
        for(int i=0;i<puzzle.length;i++)
        {
            for(int j=0;j<puzzle[0].length;j++)
            {
                if(cpv(puzzle,i,j,word)==true)
                {
                   boolean[] dipit= pwv(puzzle,i,j,word);
                   solve(puzzle,words,idx+1);
                   upwv(puzzle,i,j,dipit);
                }
                if(cph(puzzle,i,j,word)==true)
                {
                   boolean dipit= pwh(puzzle,i,j,word);
                   solve(puzzle,words,idx+1);
                   upwh(puzzle,i,j,dipit);
                }
            }
        }
    }
    public static void main(String[] args)
    {
        String[] words={chemistry,physics,maths,civics,geography,history};
        int[][] puzzle={
            {1,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,0},
            {0,0,0,0,0,0,0,1,1,0},
            {0,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,0},
            {1,0,0,0,0,0,0,0,0,0}
        } ;
        solve(puzzle,words,0);
        
    }
}