#include<iostream>
#include<vector>

using namespace std;
int main(int argc,char**argv)
{
    vector<vector<int>>v{
            {11,12,13,14,15},
            {21,22,23,24,25},
            {31,32,33,34,35},
        };
        bool b=true;
    for(int j=0;j<v[0].size();j++)
    {
        if(b)
        {
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i][j]<<" ";
            }
            b=false;
        }
        else
        {
            
            for(int i=v.size()-1;i>=0;i--)
            {
                cout<<v[i][j]<<" ";
            }
            b=true;
        }
        
    }
}