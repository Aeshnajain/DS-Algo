#include<iostream>
#include<vector>
using namespace std;
vector<int> rcheck;
vector<int> ccheck;
vector<vector<int> > bcheck;
// bool check(vector<vector<char>>&board,int n,int x,int y)
//     {
//         for(int i=0;i<board.size();i++)
//         {
//             if(board[i][y]-'0'==n || board[x][i]-'0'==n)
//             {
//                 return false;
//             }
//         }
//         int mx=(x/3)*3;
//         int my=(y/3)*3;
//         for(int i=0;i<3;i++)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 if(board[mx+i][my+j]-'0'==n)
//                 {
//                     return false;
//                 }
//             }
            
//         }
//         return true;
//     }
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
            int mask=1<<i;
            if((rcheck[x]&mask)==0 && (ccheck[y]&mask)==0 && (bcheck[x/3][y/3]&mask)==0)
            {

                board[x][y]=(char)(i+'0');
                rcheck[x]^=mask;
                ccheck[y]^=mask;
                bcheck[x/3][y/3]=bcheck[x/3][y/3]^mask;
                if(solve(board,calls,idx+1))
                {
                    return true;
                }
                rcheck[x]^=mask;
                ccheck[y]^=mask;
                bcheck[x/3][y/3]=bcheck[x/3][y/3]^mask;
                board[x][y]='.';
            }

        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> calls;
        rcheck.assign(9,0);
        ccheck.assign(9,0);
        bcheck.assign(3,vector<int>(3,0));

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')
                {
                    calls.push_back(i*board.size()+j);
                }
                else
                {
                    int num=board[i][j]-'0';
                    int mask=1<<num;
                    rcheck[i]^=mask;
                    ccheck[j]^=mask;
                    bcheck[i/3][j/3]=bcheck[i/3][j/3]^mask;
                    
                }
                
            }
        }
        solve(board,calls,0);
    }
int main(int argc,char**argv)
{
    vector<vector<char> > board {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','1','.','.','9','5','.','.','.'},
        {'.','.','9','8','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };
    solveSudoku(board);
}