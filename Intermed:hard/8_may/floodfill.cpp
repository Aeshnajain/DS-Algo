#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > dir {
        {1,0},
        {0,1},
        {0,-1},
        {-1,0}

};
vector<string> ans={"D","R","L","U"};
int solve(vector<vector<int> >&maze,int x,int y,string fans)
{
    if(x==maze.size()-1 && y==maze.size()-1)
    {
        cout<<fans<<endl;
        return 1;
    }
    
    int count=0;
    maze[x][y]=2;
    for(int i=0;i<dir.size();i++)
    {
        int mx=x+dir[i][0];
        int my=y+dir[i][1];
        if(mx>=0 && my>=0 && mx<maze.size() && my<maze.size() && maze[mx][my]==0)
        {
             count+=solve(maze,mx,my,fans+ans[i]);
        }
       

    }
    maze[x][y]=0;
    return count;
}
int main(int argc,char**argv)
{
    vector<vector<int>> maze {
            {0,1,0,0,0,0,0,1},
            {0,1,0,1,1,1,0,1},
            {0,1,0,1,0,0,0,1},
            {0,0,0,0,0,1,1,1},
            {0,1,0,1,0,0,0,0},
            {0,1,0,1,1,1,1,0},
            {0,1,0,1,1,1,1,0},
            {0,1,0,0,0,0,0,0}
        };
        int count= solve(maze,0,0,"");
        cout<<count<<endl;

}