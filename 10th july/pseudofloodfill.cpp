#include<iostream>
#include<vector>
#include<string>

using namespace std;
//a new vector and string is formed at every call. hence there was no need to append the change once done
//in the vector or string to print all the desired paths.but this is said to be an ineffective code because
//it takes a lot of memory and takes alot of time to compile and run due to formation of new vector and
//string at each step

void ff(int sr, int sc, vector<vector<int>> maze, string psf)
{
    if(sr==maze.size()-1 && sc==maze[0].size()-1)
    {
        cout<<psf<<endl;
        return;
    }
    maze[sr][sc]=2;
    if(sr<maze.size()-1 && maze[sr+1][sc]!=2 && maze[sr+1][sc]!=1)
    {
        ff(sr+1,sc,maze,psf+"d");
    }
    if(sr>0 && maze[sr-1][sc]!=2 && maze[sr-1][sc]!=1)
    {
        ff(sr-1,sc,maze,psf+"u");
    }
    if(sc<maze[0].size()-1 && maze[sr][sc+1]!=2 && maze[sr][sc+1]!=1)
    {
        ff(sr,sc+1,maze,psf+"r");
    }
    if(sc>0 && maze[sr][sc-1]!=2 && maze[sr][sc-1]!=1)
    {
        ff(sr,sc-1,maze,psf+"l");
    }
}

int main(int argc,char** argv)
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
        
        ff(0,0,maze,"");

}