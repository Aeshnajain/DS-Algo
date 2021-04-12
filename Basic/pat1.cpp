#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n; 
    cout<<"enter a number";
    cin>>n;
    int space=n/2;
    int star=1;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int x=1;x<=star;x++)
        {
            cout<<"*";
        }
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        if(i<=n/2)
        {
            space--;
            star+=2;
        }
        else
        {
            space++;
            star-=2;
        }
        cout<<endl;
    }
}