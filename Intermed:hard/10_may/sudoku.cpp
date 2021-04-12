#include<iostream>
#include<vector>
using namespace std;
bool check(vector<vector<char>>&board,int n,int x,int y)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][y]-'0'==n || board[x][i]-'0'==n)
            {
                return false;
            }
        }
        int mx=(x/3)*3;
        int my=(y/3)*3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(board[mx+i][my+j]-'0'==n)
                {
                    return false;
                }
            }
            
        }
        return true;
    }
    bool solve(vector<vector<char>>&board,vector<int> calls,int idx)
    {
        if(idx==calls.size())
        {
            return true;
        }
        int x=calls[idx]/board.size();
        int y=calls[idx]%board.size();
         
        for(int i=1;i<=9;i++)
        {
            if(check(board,i,x,y)==true)
            {
                board[x][y]=(char)(i+'0');
                if(solve(board,calls,idx+1))
                {
                    return true;
                }
                board[x][y]='.';
            }

        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> calls;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')
                {
                    calls.push_back(i*board.size()+j);
                }
            }
        }
        solve(board,calls,0);
    }
int main(int argc,char**argv)
{
    vector<vector<char> > board {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    solveSudoku(board);
}