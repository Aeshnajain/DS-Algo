#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class medianpq
{
    private:
     priority_queue<int> left;
     priority_queue<int,vector<int>,greater<int>> right;

     void handle()
     {
         if(right.size()-left.size()==2)
         {
             int val=right.top();
             right.pop();
             left.push(val);
         }
         else if(left.size()-right.size()==2)
         {
             int val=left.top();
             left.pop();
             right.push(val);
         }
     }
    
    public:
     void push(int val)
     {
        if(right.size()!=0 && val>right.top())
        {
            right.push(val);
        }
        else
        {
            left.push(val);
        }
        handle();
        
     }
     void pop()
     {
         if(right.size()>left.size())
         {
             right.pop();
         }
         else 
         {
             left.pop();
         }
     }
     int top()
     {
         if(right.size()>left.size())
         {
             return right.top();
         }
         else 
         {
             return left.top();
         }

     }
     int size()
     {
         return left.size()+right.size();
     }

};

int main(int argv,char** argc)
{
    medianpq mpq;
    mpq.push(20);
    mpq.push(5);
    mpq.push(3);
    mpq.push(17);
    int v=mpq.top();
    cout<<v<<endl;
    mpq.push(8);
    mpq.push(9);
    mpq.pop();
    v=mpq.top();
    cout<<v<<endl;





}