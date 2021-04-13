#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class mpq
{
    private:
     vector<int> v;
     bool minormax;

     void upheapify(int idx)
     {
        if(idx==0)
        {
             return;
        }
        int pi=(idx-1)/2;
        if(ishigherpriority(idx,pi))
        {
            swap(v[idx],v[pi]);
            upheapify(pi);
        }
        
    }
     void downheapify(int idx)
     {
        //  if(idx==v.size()-1)
        //  {
        //      return;
        //  }
         int lci=2*idx+1;
         int rci=2*idx+2;

         int hpi=idx;

         if(lci<v.size() && ishigherpriority(lci,hpi))
         {
             hpi=lci;
         }
         if(rci<v.size() && ishigherpriority(rci,hpi))
         {
             hpi=rci;
         }
         if(hpi!=idx)
         {
             swap(v[idx],v[hpi]);
             downheapify(hpi);
         }


     }
     bool ishigherpriority(int c,int p)
    {
        if(minormax==true) //minpq
        {
            return v[c]<v[p];
        }
        else //maxpq
        {
            return v[c]>v[p];
        }
    }
    public:
    mpq(bool minormax,vector<int>& data)
    {
        this->minormax=minormax;
        for(int i=0;i<data.size();i++)
        {
            v.push_back(data[i]);
        }

        for(int i=v.size()/2-1;i>=0;i--)
        {
            downheapify(i);
        }
    
    }
    mpq(bool minormax)
    {
        this->minormax=minormax;
    }
    void push(int i)
    {
        v.push_back(i);
        upheapify(v.size()-1);

    }
    void pop()
    {
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        downheapify(0);


    }
    int size()
    {
        return v.size();
    }
    int top()
    {
        return v[0];
    }

};

int main(int argc,char** argv)
{
    vector<int> data {10,66,34,2,36,6,23,11};
    mpq pq(true,data);

    // pq.push(10);
    // pq.push(20);
    // pq.push(55);
    // pq.push(23);
    // pq.push(99);
    // pq.push(18);
    while(pq.size()>0)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}