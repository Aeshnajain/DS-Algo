#include<iostream>
#include<vector>
#include<string>

using namespace std;

//to avoid formation of new vector and string at every call, the call is made through reference which uses
//address of the original vector and string and uses it at every call. since same vector and string is used
//the changes made initially needs to be appended to achieve the desired outcome.
// in java the problem of formation of new string cannot be dealt with because the formation of new string
//takes place while adding a new element whereas it can be dealt with in cpp because it form a new string
//during assignment and can be managed by passing the string through reference
//it is the most effective code among all.

void ff(int sr, int sc, vector<vector<int>>& maze, string& psf)
{
    if(sr==maze.size()-1 && sc==maze[0].size()-1)
    {
        cout<<psf<<endl;
        return;
    }
    maze[sr][sc]=2;
    if(sr<maze.size()-1 && maze[sr+1][sc]!=2 && maze[sr+1][sc]!=1)
    {
        psf+="d";
        ff(sr+1,sc,maze,psf);
        //psf.erase(psf.length()-1,1);
        psf.pop_back();
    }
    if(sr>0 && maze[sr-1][sc]!=2 && maze[sr-1][sc]!=1)
    {
        psf+="u";
        ff(sr-1,sc,maze,psf);
        //psf.erase(psf.length()-1,1);
        psf.pop_back();
    }
    if(sc<maze[0].size()-1 && maze[sr][sc+1]!=2 && maze[sr][sc+1]!=1)
    {
        psf+="r";
        ff(sr,sc+1,maze,psf);
        //psf.erase(psf.length()-1,1);
        psf.pop_back();
    }
    if(sc>0 && maze[sr][sc-1]!=2 && maze[sr][sc-1]!=1)
    {
        psf+="l";
        ff(sr,sc-1,maze,psf);
        //psf.erase(psf.length()-1,1);
        psf.pop_back();
    }
    maze[sr][sc]=0;
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
        string psf="";
        
        ff(0,0,maze,psf);

}