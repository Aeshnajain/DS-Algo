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

class bipair
{
    public:
     int v;
     int l;
};

vector<vector<edge> > graph;

void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<":";
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


bool bipart(int i,vector<int>& visited)
{
    queue<int> q;
    q.push(i);
    int c=0;
    while(q.size()>0)
    {
        int size=q.size();
        c=c%2;
        for(int i=0;i<size;i++)
        {
            int vrtx=q.front();
            q.pop();
            if(visited[vrtx]!=-1 && visited[vrtx]!=c)
            {
                return false;
            }
            visited[vrtx]=c;
            for(int nbr=0;nbr<graph[vrtx].size();nbr++)
            {
                edge e=graph[vrtx][nbr];
                if(visited[e.nbr]==-1)
                {
                   q.push(e.nbr);
                }
            }
        }
        c++;
    }
    return true;

    
    
}




bool isbipart(int i,vector<int>& visited)
{
    queue<bipair> q;
    bipair bp;
    bp.v=i;
    bp.l=1;
    q.push(bp);
    while(q.size()>0)
    {
        bipair rem=q.front();
        q.pop();
        if(visited[rem.v]!=0)
        {
            int ol=visited[rem.v];
            int cl=rem.l;
            if(ol%2!=cl%2)
            {
                return false;
            }
            else
            {
                continue;
            }
            
        }
        visited[rem.v]=rem.l;

        for(int i=0;i<graph[rem.v].size();i++)
        {
            edge e=graph[rem.v][i];
            if(visited[e.nbr]==0)
            {
                bipair bp3;
                bp3.v=e.nbr;
                bp3.l=rem.l+1;
                q.push(bp3);
            }
        }
    }
    return true;

    
    
}
bool cbp()
{
   vector<int> visited (graph.size(),0);
   bool n;
   for(int i=0;i<visited.size();i++)
   {
       if(visited[i]==0)
       {
          n=isbipart(i,visited);
          if(n==false)
          {
              return false;
          }
       }
   } 
   return true;
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
    addedge(6,4,8);
    //addedge(2,5,5);
    vector<int> visited(7,-1);
    cout<<bipart(0,visited)<<endl;
    display();

    bool ans=cbp();
    cout<<ans<<endl;

    

}
