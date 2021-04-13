#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void demo()
{
    priority_queue<int> pq;
    pq.push(20);
    pq.push(10);
    pq.push(2);
    pq.push(6);
    pq.push(4);
}

void printksmallest(vector<int>& v,int k)
{
    priority_queue<int> pq;
    int i=0;
    while(i<k)
    {
        pq.push(v[i]);
        i++;
    }
    while(i<v.size())
    {
        if(pq.top()>v[i])
        {
            pq.pop();
            pq.push(v[i]);
        }
        i++;
    }

    while(pq.size()>0)
    {
        int val=pq.top();
        pq.pop();
        cout<<val<<" ";
    }

}

int main(int argc,char** argv)
{
    //demo();
    vector<int> v{2,15,6,4,3,27,8,0,33,40};
    int k=4;
    printksmallest(v,k);
}

