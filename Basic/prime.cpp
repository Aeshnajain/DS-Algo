#include<iostream>

using namespace std;

int main(int argc,char** argv)
{
    int n;
    cout<<"enter the number";
    cin>>n;
    bool flag=true;
    for( int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            flag=false;
            break;
        }
    }
    if (flag==true)
    {
        cout<<"prime";
    }
    else 
    {
        cout<<"composite";
    }
}