#include<iostream>

using namespace std;

int main(int argc, char** argv )
{
    int a,b,temp;
    cout<<"enter 2 numbers";
    cin>>a>>b;
    while(b>0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    cout<<temp;
}