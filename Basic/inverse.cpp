#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cout<<"enter the number";
    cin>>n;
    int m=0;
    int i=1;
    int y;
    while(n>0)
    {
        y=n%10;
        m=m+(i*(int)pow(10,y-1));
        i++;
        n=n/10;

    }
    cout<<m;
}