#include<iostream>
#include<vector>
using namespace std;

int XOR(int num)
{
    long long a=1;
    long long b=1;
    long long sum=0;
    for(int i=0;i<num;i++)
    {
       sum+=a*a;
       int temp=a;
       a=b;
       b=b+temp;
    }
    return sum;
}
int main(int argc,char**argv)
{
    cout<<XOR(5)<<endl;
}