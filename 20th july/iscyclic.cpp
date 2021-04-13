#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

class edge
{
    public:
     int nbr;
     int wght;
};

vector<vector<edge> > graph;

void display()
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            edge ne=graph[i][j];
            cout<<"[ "<<ne.nbr<<"->"<<ne.wght<<" ]";
        }
        cout<<endl;
    }
}

void addedge(int v1,int v2,int wght)
{
    edge e1;
    e1.nbr=v2;
    e1.wght=wght;
    graph[v1].push_back(e1);

    edge e2;
    e2.nbr=v1;
    e2.wght=wght;
    graph[v2].push_back(e2);


}


string gscc(int src,vector<bool>& visited)
{
    string comp="";
    queue<int> q;
    q.push(src);
    while(q.size()>0)
    {
        int rem=q.front();
        q.pop();
        if(visited[rem]==true)
        {
            continue;
        }
        visited[rem]=true;
        comp+=to_string(rem);
        for(int i=0;i<graph[rem].size();i++)
        {
            edge e=graph[rem][i];
            if(visited[e.nbr]==false)
            {
                q.push(e.nbr);
            }
        }
    }
    return comp;
}

bool gcc()
{
    int counter=0;
    vector<bool> visited (graph.size(),false);
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==false)
        {
            gscc(i,visited);
            counter++;
            if(counter==2)
            {
                return false;
            }
        }
    }
    return true;
}

bool iscyclic(int v,vector<bool> visited)
{
    queue<int> q;
    q.push(v);

    while(q.size()>0)
    {
        int rem=q.front();
        q.pop();

        if(visited[rem]==true)
        {
            return true;
        }
        visited[rem]=true;

        for(int i=0;i<graph[rem].size();i++)
        {
            edge e=graph[rem][i];
            if(visited[e.nbr]==false)
            {
                q.push(e.nbr);
            }
        }
    }
    return false;
}

bool callcyc()
{
    vector<bool> visited (graph.size(),false);
    bool n;
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==false)
        {
           n=iscyclic(i,visited);
          
        }
    }
    return n;
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

    addedge(0,1,10);
    addedge(1,2,10);
    addedge(2,3,10);
    addedge(0,3,10);
    addedge(3,4,2);
    addedge(4,5,3);
    addedge(5,6,3);
    addedge(4,6,8);
    addedge(2,5,5);

    display();

    bool iscon=gcc();
    cout<<iscon<<endl;
    bool c=callcyc();
    cout<<c<<endl;

}
