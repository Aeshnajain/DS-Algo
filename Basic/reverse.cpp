#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cout<<"enter the number";
    cin>>n;
    int m=0;
    int y;
    while(n!=0)
    {
        y=n%10;
        m=m*10+y;
        n=n/10;
    }
    cout<<"the reversed number is "<<m;
}