#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class point
{
    public:
    int li;
    int di;
    int val;
    public:
        point(int li,int di,int val)
        {
            this->li=li;
            this->di=di;
            this->val=val;
        }
        bool operator>(const point&other) const
        {
            if(this->val>other.val)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

};

int main(int argc,char** argv)
{
    vector<vector<int>> v={
        {1,6,9},
        {2,4,7,8},
        {3,5,11}
    };
    priority_queue<point,vector<point>,greater<point>> pq;


    
    for(int i=0;i<v.size();i++)
    {
        point p(i,0,v[i][0]);
        pq.push(p);

    }

    while(pq.size()>0)
    {

        point p=pq.top();
        pq.pop();
        cout<<p.val<<" ";
        p.di++;
        if(p.di<v[p.li].size())
        {
            point r(p.li,p.di,v[p.li][p.di]);
            pq.push(r);
        }
    }
    cout<<endl;
    

    

}