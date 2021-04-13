#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> gr(int sr,int sc,int dr,int dc)
{
    if(sc==dc && sr==dr)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> nh;
    vector<string> nv;
    vector<string> ans;
    if(sc<dc)
    {
        nh=gr(sr,sc+1,dr,dc);
    }
    if(sr<dr)
    {
        nv=gr(sr+1,sc,dr,dc);
    }
    for(int i=0;i<nh.size();i++)
    {
        string hor=nh[i];
        string final='h'+hor;
        ans.push_back(final);

    }
   for(int i=0;i<nv.size();i++)
    {
        string ver=nv[i];
        string final='v'+ver;
        ans.push_back(final);

    } 
    return ans;
    
    
}

int main(int argc,char** argv)
{
    vector<string> path=gr(0,0,2,2);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<endl;
    }
}