#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>

using namespace std;

class edge
{
    public:
     int nbr;
};
vector<vector<edge> > graph;






void display()
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            edge ne=graph[i][j];
            cout<<"[ "<<i<<"->"<<ne.nbr<<" ]";
        }
        cout<<endl;
    }
}



void directedaddedge(int v1,int v2)
{
    edge e1;
    e1.nbr=v2;
    graph[v1].push_back(e1);


}

void topsort(int v,vector<bool>& visited,stack<int>& s)
{
    visited[v]=true;

    for(int i=0;i<graph[v].size();i++)
    {
        edge e=graph[v][i];
        if(visited[e.nbr]==false)
        {
            topsort(e.nbr,visited,s);
        }
        
    }
    s.push(v);
}

void cts()
{
    vector<bool> visited (graph.size(),false);
    stack<int> s;
    for(int n=0;n<graph.size();n++)
    {
        if(visited[n]==false)
        {
            topsort(n,visited,s);
        }
    }

    while(s.size()>0)
    {
        int rem=s.top();
        s.pop();
        cout<<rem<<" ";
    }
    cout<<endl;
}


int main(int argc,char** argv)
{
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());

    directedaddedge(0,1);
    directedaddedge(1,2);
    directedaddedge(2,3);
    directedaddedge(4,3);
    directedaddedge(0,4);
    directedaddedge(5,4);
    directedaddedge(5,6);
    directedaddedge(6,3);
   // addedge(2,5,5);

   display();
   cts();
    //prims();



}
