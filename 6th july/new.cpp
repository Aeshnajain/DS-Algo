#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void getsol(int i,int j,vector<vector<char>>grid,int&ans)
{
    if(i==grid.size()-1&&j==grid[0].size()-1)
    {
        cout<<i<<" "<<j<<endl;
        ans=ans+1;
        return;
    }
    cout<<i<<" "<<j<<endl;
    for(int r=1;r<=grid.size()-1-i;r++)
    {
        if(r+i<grid.size() && grid[r+i][j]=='.')
        {
            getsol(i+r,j,grid,ans);
        }
    }
    for(int c=1;c<=grid[0].size()-1-j;c++)
    {
        if(c+j<grid[0].size() && grid[i][j+c]=='.')
        {
            getsol(i,j+c,grid,ans);
        }
    }
    for(int r=1,c=1;r<=grid.size()-1-i&&c<=grid[0].size()-1-j;r++,c++)
    {
        if(r+i<grid.size() && c+j<grid[0].size() && grid[r+i][c+j]=='.')
        {
            getsol(i+r,j+c,grid,ans);
        }
    }
}

int main() {

    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<char>>grid(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int ans=0;
    getsol(0,0,grid,ans);
    cout<<ans%1000000007<<endl;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}