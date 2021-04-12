#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(int idx,int n)
{
    if(idx>=n)
    {
        return;
    }
    int lastidx=0;
    if(idx/10==0)
    {
        lastidx=idx+8;
    }
    else
    {
        lastidx=idx+9;
    }
    for(int i=idx;i<=lastidx;i++)
    {
        if(i<n)
        {
          cout<<i<<endl;
          solve(i*10,n);
        }
    }
    
}
int main() {
    int n;
    cin>>n;
    solve(1,n);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

