#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int> >& board,int x,int y)
{
    vector<vector<int> > dir {
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1}
    };
    for(int d=0;d<dir.size();d++)
    {
        for(int r=0;r<board.size();r++)
        {
            int mx=x+r*dir[d][0];
            int my=y+r*dir[d][1];
            if(mx>=0 && my>=0 && mx<board.size() && my<board.size())
            {
                if(board[mx][my]==1)
                {
                    return false;
                }
            }
            else
            {
                break;
            }
            
        }
    }
    return true;


}

bool checknew(vector<vector<int> >& board,int x,int y)
{
    vector<vector<int> > dir {
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1}
    };
    for(int d=0;d<dir.size();d++)
    {
        for(int r=0;r<board.size();r++)
        {
            int mx=x+r*dir[d][0];
            int my=y+r*dir[d][1];
            if(mx>=0 && my>=0 && mx<board.size() && my<board.size())
            {
                if(board[mx][my]==1)
                {
                    return false;
                }
            }
            else
            {
                break;
            }
            
        }
    }
    return true;


}

int nqueen(vector<vector<int> >&board,int tq,int idx)
{
    if(tq==0)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                cout<<board[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return 1;

    }
    int count=0;
    for(int i=idx;i<board.size()*board.size();i++)
    {
        int x=i/board.size();
        int y=i%board.size();
        if (check(board,x,y))
        {
            board[x][y]=1;
            count+=nqueen(board,tq-1,i+1);
            board[x][y]=0;
            
        }
    }
    return count;
}

int nqueensubcom(vector<vector<int> >&board,int tq,int idx)
{
    if(idx==board.size()*board.size() || tq==0)
    {
        if(tq==0)
        {
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board.size();j++)
                {
                    cout<<board[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl;
            return 1;

        }
        else
        {
            return 0;
        }
    }
    int count=0;
    int x=idx/board.size();
    int y=idx%board.size();
    if(check(board,x,y))
    {
        board[x][y]=1;
        count+=nqueensubcom(board,tq-1,idx+1);
        board[x][y]=0;
    }
    count+=nqueensubcom(board,tq,idx+1);
    
    return count;
    
}
int nqueensubperm(vector<vector<int> > board,int tq,int idx)
{
    if(idx==board.size()*board.size() || tq==0)
    {
        if(tq==0)
        {
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board.size();j++)
                {
                    cout<<board[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl;
            return 1;

        }
        else
        {
            return 0;
        }
    }
    int count=0;
    int x=idx/board.size();
    int y=idx%board.size();
    if(checknew(board,x,y))
    {
        board[x][y]=1;
        count+=nqueensubperm(board,tq-1,0);
        board[x][y]=0;
    }
    count+=nqueensubperm(board,tq,idx+1);
    
    return count;
    

}
int main(int argc,char**argv)
{
    vector<vector<int> > board {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    int q=board.size();
    int ans=nqueensubperm(board,q,0);
    cout<<ans<<endl;

}