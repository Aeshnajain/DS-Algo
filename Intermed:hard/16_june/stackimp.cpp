#include<iostream>

using namespace std;

class Mystack
{
        int size;
        int tos=-1;
        int*arr;
    public: 
        Mystack()
        {
            this->size=INT_MAX;
            this->arr=new int[size];
        }
        Mystack(int v)
        {
            this->size=v;
            this->arr=new int[size];
        }
        void push(int val)
        {
            this->tos++;
            if(this->tos==size)
            {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[this->tos]=val;
        }
        void pop()
        {
            if(this->tos==-1)
            {
                cout<<"Stack Underflow"<<endl;
                return;
            }
            this->tos--;
        }
        int top()
        {
            if(this->tos==-1)
            {
                cout<<"Not Applicable"<<endl;
                return -1;
            }
            return arr[this->tos];
        }
        bool isEmpty()
        {
            return this->tos==-1;
        }
    


    

};
int main(int argc,char**argv)
{
    Mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    while(!st.isEmpty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    st.pop();
}