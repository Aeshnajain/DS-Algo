#include<iostream>
#include<vector>

using namespace std;
void filter(vector<int>& v)
{
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]>50)
        {
            v.erase(v.begin()+i);
        }
    } 
    cout<<v.data();
    cout<<endl;
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(int argc,char** argv)
{
    vector <int> v {1,56,45,34,22,9};
    filter(v);
    cout<<v.data();
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}