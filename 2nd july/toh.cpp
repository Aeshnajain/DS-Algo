#include<iostream>

using namespace std;

void toh(int n,int st,int dt,int ht)
{
    if (n==0)
    {
        return;
    }
    toh(n-1,st,ht,dt);
    cout<<n<<"["<<st<<"->"<<dt<<"]"<<endl;
    toh(n-1,ht,dt,st);
    
}


int main(int argc,char** argv)
{
    int n;
    cin>>n;
    toh(n,1,2,3);
}