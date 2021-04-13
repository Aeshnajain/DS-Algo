#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void printsl(vector<int> v,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(v[i]);

    }

    while(pq.size()>0)
    {
        cout<<pq.top()<<" ";
        pq.pop();
        k++;
        if(k<v.size())
         pq.push(v[k]);
        
    }
    cout<<endl;
}

void downheapify(vector<int>& pq,int idx,int ve)
{
    int lci=2*idx+1;
    int rci=2*idx+2;

    int hpi=idx;

    if(lci<=ve && pq[lci]>pq[hpi])
    {
        hpi=lci;
    }
    if(rci<=ve && pq[rci]>pq[hpi])
    {
        hpi=rci;
    }
    if(hpi!=idx)
    {
        swap(pq[idx],pq[hpi]);
        downheapify(pq,hpi,ve);
    }

}

void heapsort(vector<int>& arr)
{
    for(int i=arr.size()/2-1;i>=0;i--)
    {
        downheapify(arr,i,arr.size()-1);
    }

    for(int i=1;i<=arr.size()-1;i++)
    {
        swap(arr[0],arr[arr.size()-i]);
        downheapify(arr,0,arr.size()-i-1);
    }

}

int main(int argc,char** argv)
{
    vector<int> v={5,14,2,8,15,25,35,20,40,50,42};
    heapsort(v);
    int i=0;
    while(i<v.size())
    {
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;
    // int k=2;
    // printsl(v,k);
}