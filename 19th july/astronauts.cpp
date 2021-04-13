#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class astro
{
    public:
    int nbr;
};
vector<vector<astro> > graph;
void addastro(int v1,int v2)
{
    astro e1;
    e1.nbr=v2;
    graph[v1].push_back(e1);

    astro e2;
    e2.nbr=v1;
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
            astro e=graph[rem][i];
            if(visited[e.nbr]==false)
            {
                q.push(e.nbr);
            }
        }
    }
    return comp;
}

vector<string> gcc()
{
    vector<string> comps;
    vector<bool> visited (graph.size(),false);
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==false)
        {
            string comp=gscc(i,visited);
            comps.push_back(comp);
        }
    }
    return comps;
}




int main(int argc,char** argv)
{
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());
    graph.push_back(vector<astro>());

    addastro(1,7);
    addastro(2,6);
    addastro(3,4);
    addastro(4,7);
    addastro(8,2);

    vector<string> nations=gcc();
    int teams=0;

    for(int i=0;i<nations.size();i++)
    {
        for(int j=i+1;j<nations.size();j++)
        {
            teams+=nations[i].size()*nations[j].size();
        }
    }
    cout<<teams<<endl;
}