#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//leetcode 207==============================
//Kahn's Algorithm==============================


class Solution {
public:
    bool getans(vector<vector<int>>&graph)
    {
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                indegree[graph[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(q.size()!=0)
        {
            int vrtx=q.front();
            q.pop();
            ans.push_back(vrtx);
            for(int i=0;i<graph[vrtx].size();i++)
            {
                indegree[graph[vrtx][i]]--;
                if( indegree[graph[vrtx][i]]==0)
                {
                    q.push(graph[vrtx][i]);
                }
            }
        }
        return ans.size()==graph.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        return getans(graph);
        
    }
};

