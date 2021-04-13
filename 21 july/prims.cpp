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

class ppair
{
    public:
     int v;
     int av;
     int c;

     ppair(int v,int av,int c)
     {
         this->v = v;
         this->av = av;
         this->c = c;
     }
     ppair()
     {};
     

     bool operator<(const ppair& other) const
     {
         return this->c<other.c;
     }
     bool operator>(const ppair& other) const
     {
         return this->c>other.c;
     }
};

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

void display(vector<vector<edge> > g)
{
    for(int i=0;i<g.size();i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            edge ne=g[i][j];
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

void addedge(vector<vector<edge> >& g,int v1,int v2,int wght)
{
    edge e1;
    e1.nbr=v2;
    e1.wght=wght;
    g[v1].push_back(e1);

    edge e2;
    e2.nbr=v1;
    e2.wght=wght;
    g[v2].push_back(e2);
}

void prims()
{
    vector<vector<edge> > mst (graph.size(),vector<edge>());

    vector<bool> visited (graph.size(),false);
    ppair r(0,-1,0);
     
    priority_queue<ppair,vector<ppair>,greater<ppair> > pq;

    pq.push(r);

    while(pq.size()>0)
    {
        ppair rem=pq.top();
        pq.pop();

        if(visited[rem.v]==true)
        {
            continue;
        }
        visited[rem.v]=true;

        if(rem.av!=-1)
        {
            addedge(mst,rem.v,rem.av,rem.c);
        }

        for(int i=0;i<graph[rem.v].size();i++)
        {
            edge e=graph[rem.v][i];
            if(visited[e.nbr]==false)
            {
                ppair np(e.nbr,rem.v,e.wght);
                pq.push(np);
            }
        }
    }
    display(mst);

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

    addedge(0,1,20);
    addedge(1,2,10);
    addedge(2,3,20);
    addedge(0,3,40);
    addedge(3,4,2);
    addedge(4,5,3);
    addedge(5,6,3);
    addedge(4,6,8);
   // addedge(2,5,5);

   // display();
    prims();



}
