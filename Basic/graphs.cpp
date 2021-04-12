#include<iostream>
#include<vector>

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

bool haspath(int src,int d,vector<bool> visited)
{
    visited[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        edge ne=graph[src][i];
    }
}
int main(int argc,char** argv)
{
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

    display();
    vector<bool> visited; 
    haspath(0,6,visited);
    

}
