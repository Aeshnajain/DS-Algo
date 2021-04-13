#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> ga(int sr,int sc,int dr,int dc,int&res)
{
    if(sc==dc && sr==dr)
    {
         res++;
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> nh;
    vector<string> nv;
    vector<string> nd;
    vector<string> ans;
    for(int i=1;i<=dc-sc;i++)
    {
       nh=ga(sr,sc+i,dr,dc,res); 
       for(int j=0;j<nh.size();j++)
       {
          ans.push_back("h"+to_string(i)+nh[j]);
       }
    }
    for(int i=1;i<=dr-sr;i++)
    {
       nv=ga(sr+i,sc,dr,dc,res); 
       for(int j=0;j<nv.size();j++)
       {
          ans.push_back("v"+to_string(i)+nv[j]);
       }
    }
    for(int i=1;i<=(dc-sc) && (dr-sr);i++)
    {
       nd=ga(sr+i,sc+i,dr,dc,res); 
       for(int j=0;j<nd.size();j++)
       {
          ans.push_back("d"+to_string(i)+nd[j]);
       }
    }
    
    return ans;
    
    
}

int main(int argc,char** argv)
{
   int res=0;
    vector<string> path=ga(0,0,2,2,res);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<endl;
    }
    cout<<res<<endl;
}