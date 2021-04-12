#include<iostream>
#include<vector>

using namespace std;

class edge
{
     
    public:
     int v=0;
     int w=0;
     edge(int v,int w)
     {
         this->v=v;
         this->w=w;
     }
};
int N=7;
vector<vector<edge>>graph(7);

void addEdge(int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));

}

void constructGraph()
{
    addEdge(0,1,2);
    addEdge(1,3,6);
    addEdge(2,3,4);
    addEdge(2,4,4);
    addEdge(3,4,4);
    addEdge(0,4,2);
}

bool hasPath(int src,int dest,vector<bool>&ch)
{
    if(src==dest)
    {
        return true;
    }
    ch[src]=true;
    bool ans=false;
    for(int i=0;i<graph[src].size();i++)
    {
        if(ch[graph[src][i].v]==false)
        {
            ans=ans||hasPath(graph[src][i].v,dest,ch);
        }

    }
    ch[src]=false;
    return ans;
}

int allPath(int src,int dest,vector<bool>&ch)
{
    if(src==dest)
    {
        return 1;
    }
    ch[src]=true;
    int ans=0;
    for(int i=0;i<graph[src].size();i++)
    {
        if(ch[graph[src][i].v]==false)
        {
            ans+=allPath(graph[src][i].v,dest,ch);
        }

    }
    ch[src]=false;
    return ans;
}

void check(vector<bool>ch,int i)
{
    int size=1;
    while(--size>0)
    {
        cout<<size<<" ";
    }
    cout<<endl;
    size=9;
    while(size>0)
    {
        cout<<size<<" ";
        size--;
    }
    cout<<endl;
}

int main(int argc,char**argv)
{
    constructGraph();
    vector<bool>ch(7,false);
    //cout<<allPath(0,4,ch)<<endl;
    check(ch,0);
}

