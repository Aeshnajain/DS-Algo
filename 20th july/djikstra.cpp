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

class dpair
{
    public:
     int v;
     int c;
     string p;

     dpair(int v,int c,string p)
     {
         this->v= v;
         this->c =c;
         this->p =p;
     }
     dpair()
     {}

     bool operator<(const dpair& other) const{
         return this->c<other.c;
     }
     bool operator>(const dpair& other) const{
         return this->c>other.c;
     }
};

void djikstra(int src)
{
    priority_queue<dpair, vector<dpair> ,greater<dpair> > pq;
    dpair r(src,0,to_string(src));
    pq.push(r);
    vector<bool> visited (graph.size(),false);
    while(pq.size()>0)
    {
        dpair rem=pq.top();
        pq.pop();
        if(visited[rem.v]==true)
        {
            continue;
        }
        visited[rem.v]=true;

        cout<<rem.v<<" @ "<<rem.c<<" via "<<rem.p<<endl;

        for(int i=0;i<graph[rem.v].size();i++)
        {
            edge e=graph[rem.v][i];
            if(visited[e.nbr]==false)
            {
               dpair p(e.nbr,rem.c+e.wght,rem.p+to_string(e.nbr));
               pq.push(p);

            }
        }

    }

}


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
    addedge(0,3,40);
    addedge(3,4,2);
    addedge(4,5,3);
    addedge(5,6,3);
    addedge(4,6,8);
   // addedge(2,5,5);

    //display();
    djikstra(0);



}
