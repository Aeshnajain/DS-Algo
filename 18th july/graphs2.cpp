#include<iostream>
#include<vector>
#include<climits>

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
    if(src==d)
    {
        return true;
    }
    visited[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        edge ne=graph[src][i];
        if(visited[ne.nbr]==false)
        {
          bool n=haspath(ne.nbr,d,visited);
          if(n==true)
          {
            return true;
          }

        } 
    }
    return false;
}

int sd=INT_MAX;
string sp;
int ld=INT_MIN;
string lp;
int cd=INT_MAX;
string cdp;
int fd=INT_MIN;
string fdp;

void printpath(int src,int d,vector<bool>& visited,string asf,int dist,int factor)
{
    if(src==d)
    {
        dist=dist+d;
        if(dist<sd)
        {
            sd=dist;
            sp=asf;
        }
        if(dist>ld)
        {
            ld=dist;
            lp=asf;
        }
        cout<<asf<<" @ "<<dist<<endl;
        if(dist>factor && dist<cd)
        {
            cd=dist;
            cdp=asf;
        }
        if(dist<factor && dist>fd)
        {
            fd=dist;
            fdp=asf;
        }
        
        return;

    }
    visited[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        edge e=graph[src][i];
        if(visited[e.nbr]==false)
        {
            printpath(e.nbr,d,visited,asf+to_string(e.nbr),dist+e.wght,factor);
        }

    }
    visited[src]=false;
}

void hamiltonian(int src,vector<bool>& nvisited,string asf,int count,int os)
{
    if(count==graph.size()-1)
    {
        cout<<os<<asf;
        for(int i=0;i<graph[os].size();i++)
        {
            edge m=graph[os][i];
            if(m.nbr+48 == asf[asf.size()-1] )
            {
                cout<<"*"<<endl;
                return;
            }
            
        }

cout<<"."<<endl;
return;
        
        
    }
    nvisited[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        edge e=graph[src][i];
        if(nvisited[e.nbr]==false)
        {
            hamiltonian(e.nbr,nvisited,asf+to_string(e.nbr),count+1,os);
        }
    }
    nvisited[src]=false;

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
    vector<bool> visited (7,false); 
    bool n=haspath(0,6,visited);
    cout<<n<<endl;
    printpath(0,6,visited,"",0,45);
    cout<<sd<<" @ "<<sp<<endl;
    cout<<ld<<" @ "<<lp<<endl;
    cout<<cd<<" @ "<<cdp<<endl;
    cout<<fd<<" @ "<<fdp<<endl;

    vector<bool> nvisited (7,false);
    hamiltonian(0,nvisited,"",0,0);

}
