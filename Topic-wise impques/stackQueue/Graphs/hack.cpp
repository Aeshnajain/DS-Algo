#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getans(int x,int y,vector<vector<int>>&graph,vector<bool>&vis)
{
    queue<int> q;
    q.push(x);
    vis[x]=true;
    int level=0;
    while(q.size()!=0)
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int t=q.front();
            q.pop();
            if(t==y)
            {
                return level;
            }
            for(int e:graph[t])
            {
                if(vis[e]!=true)
                {
                    vis[e]=true;
                   q.push(e);
                }
            }
        }
         level++;
        
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int v;
        cin>>v;
        int m;
        cin>>m;
        int x;
        cin>>x;
        int y;
        cin>>y;
       
        vector<vector<int>>graph(v+1,vector<int>());
        for(int j=0;j<m;j++)
        {
            int p;
            cin>>p;
            int q;
            cin>>q;
            int a;
            cin>>a;
            int b;
            cin>>b;
            for(int n=p;n<=q;n++)
            {
                for(int c=a;c<=b;c++)
                {
                    if(n==c)
                     continue;
                    graph[n].push_back(c);
                }
            }
        }
         if(x==y)
        {
            cout<<"0"<<endl;
            continue;
        }
        vector<bool>vis(v+1,false);
        int ans=getans(x,y,graph,vis);
        cout<<ans<<endl;
    }
	// your code goes here
	return 0;
}

