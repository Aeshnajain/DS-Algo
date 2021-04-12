#include<iostream>
#include<vector>
using namespace std;
bool nknight(vector<vector<int> >&board,int count,int idx)
{
    if(count==board.size()*board.size())
    {
        int x=idx/board.size();
        int y=idx%board.size();
        board[x][y]=count;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                cout<<board[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    bool res=false;
    vector<vector<int> > dir {
        {+1,+2},
        {+2,-1},
        {+2,+1},
        {-2,-1},
        {-2,1},
        {-1,-2},
        {-1,+2},
        {1,-2},
    };
    int x=idx/board.size();
    int y=idx%board.size();
    board[x][y]=count;
    // cout<<idx<<endl;
    for(int d=0;d<dir.size();d++)
    {
        for(int r=1;r<=1;r++)
        {
            int mx=x+r*dir[d][0];
            int my=y+r*dir[d][1];
             if(mx>=0 && my>=0 && mx<board.size() && my<board.size())
            {
                if(board[mx][my]==0)
                {
                   res=res || nknight(board,count+1,mx*board.size()+my);
                }
            }
            else
            {
                break;
            }
        }
    }
    board[x][y]=0;
    return res;

}
int main(int argc,char**argv)
{
    vector<vector<int> > board {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };
   
    int k=board.size();
    nknight(board,1,0);
}