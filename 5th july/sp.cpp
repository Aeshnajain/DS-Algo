#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> vsp(int src)
{
    if(src==0)
    {
        vector<string> base;
        base.push_back("");
        return base;

    }
    vector<string> std;
    for(int step=1;step<=3;step++)
    {
        if(src>=step)
        {
            int nbr=src-step;
            vector<string> ntd=vsp(nbr);
            for(int i=0;i<ntd.size();i++)
            {
                string nbrtodest=ntd[i];
                string scrtodest=to_string(step)+ nbrtodest;
                std.push_back(scrtodest);
            }
        }
    }
    return std;

}

int main(int argc,char** argv)
{
    vector <string> ans= vsp(7);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}