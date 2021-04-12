#include<iostream>
#include<vector>
#include<string>

using namespace std;

class mystack{
    private:
      int size=5;
      vector<int>myarr;
      int tos=-1;
    public:
        mystack()
        {
            myarr.resize(size,-1);
        }

        void push_(int val)
        {
            if(tos+1==size)
            {
                throw ("StackOverflow");
            }
            else 
            {
               myarr[tos+1]=val;
               tos++;
            }
        }
        
        void push(int val)
        {
            try{
                push_(val);
            }
            catch(const char* msg){
                cout<<msg<<endl;
            }
        }

        int pop_()
        {
            if(tos==-1)
            {
                throw("StackUnderflow");
            }
            int val=myarr[tos];
            tos=tos-1;
            return val;

        }

        int pop()
        {
            try{
                return pop_();
            }
            catch(const char* s)
            {
                cout<<s<<endl;
            }
        }

        int front()
        {
            if(tos==-1)
            {
                throw ("StackUnderflow");
            }
            else return myarr[tos];
        }

        void display()
        {
            for(int i=0;i<=tos;i++)
            {
                cout<<myarr[i]<<" ";
            }
            cout<<endl;
        }
};