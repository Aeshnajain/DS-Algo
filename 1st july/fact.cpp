#include<iostream>

using namespace std;

int fac(int n)
{
    if(n==0)
    {
        return 1;
    }
    int m=n*fac(n-1);
    return m; 
}

int main(int argc,char** argv)
{
    int m=fac(5);
    cout<<m;

}