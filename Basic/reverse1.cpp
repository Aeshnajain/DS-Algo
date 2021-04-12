#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    cout<<"enter the number";
    int n;
    cin>>n;
    int y;

    while(n!=0)
    {
        y=n%10;
        cout<<y;
        n=n/10;
    }
}