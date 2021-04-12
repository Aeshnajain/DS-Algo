#include<iostream>
#include<vector>

using namespace std;

bool canplace(vector<vector<int>> sudoku,int r,int c,int num)
{
    for(int i=0;i<sudoku.size();i++)
    {
        if(sudoku[r][i]==num || sudoku[i][c]==num)
        {
            return false;
        }
    }
    for(int i=(r/3)*3;i<((r/3)*3)+3;i++)
    {
        for(int j=(c/3)*3;j<((c/3)*3)+3;j++)
        {
            if(sudoku[i][j]==num)
            {
                return false;
            }
        }
    }
    return true;
}

int solvesudoku(vector<vector<int>> sudoku,int idx)
{
    if(idx==sudoku.size()*sudoku[0].size())
    {
        for(int i=0;i<sudoku.size();i++)
        {
            for(int j=0;j<sudoku[0].size();j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    int r=idx/sudoku[0].size();
    int c=idx%sudoku[0].size();
    int ans=0;
    if(sudoku[r][c]!=0)
    {
        return solvesudoku(sudoku,idx+1);
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(canplace(sudoku,r,c,i))
            {
                sudoku[r][c]=i;
                ans+=solvesudoku(sudoku,idx+1);
                sudoku[r][c]=0;
            }
        }
    }
    return ans;
    
}

int main(int argc,char**argv)
{
    vector<vector<int>> sudoku {{3, 0, 0, 0, 0, 0, 0, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};
         cout<<solvesudoku(sudoku,0)<<endl;
}