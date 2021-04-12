#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class node
{
    public:
    int data;
    vector<node*>children;
    node(int d)
    {
        this->data=d;
    }
};
node* constructgt(vector<int>& arr)
{
    stack<node*>st;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]!=-1)
        {
            node*nn=new node(arr[i]);
            st.push(nn);
        }
        else 
        {
            node*child=st.top();
            st.pop();
            st.top()->children.push_back(child);
        }
    }
    return st.top();
}

void displaygt(node*root)
{
    cout<<root->data<<"->";
    for(node*child:root->children)
    {
        cout<<child->data<<" ";
    }
    cout<<endl;
    for(node*child:root->children)
    {
        displaygt(child);
    }

}

void preordergt(node*root)
{
    cout<<root->data<<" ";
    for(node*child:root->children)
    {
        preordergt(child);
    }

}

bool mirror(node*root1,node*root2) //both mirror and symmetry 
                                   //can be solved using this code only
{
    if(root1->children.size()!=root2->children.size() || root1->data!=root2->data)
    {
        return false;
    }
    for(int i=0,j=root2->children.size()-1;j>=0;i++,j--)
    {
        if(!mirror(root1->children[i],root2->children[j]))
        {
            return false;
        }
    }
    return true;
}

node* linearise(node*root)
{
    if(root->children.size()==0)
    {
        return root;
    }
    int n=root->children.size();
    node*lasttail=linearise(root->children[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        node*secondlasttail=linearise(root->children[i]);
        secondlasttail->children.push_back(root->children[i+1]);
        root->children.pop_back();
    }
    return lasttail;
}

node* flatten(node*root)
{
    vector<node*> newchildren;
    for(node*child:root->children)
    {
        node*flatnode=flatten(child);
        newchildren.push_back(flatnode);
        for(node*fchild:flatnode->children)
        {
            newchildren.push_back(fchild);
        }
        for(node*fchild:flatnode->children)
        {
           flatnode->children.pop_back();
        }
    }
    root->children=newchildren;
    return root;
}


int main(int argc,char**argv)
{
    vector<int> v{10,20,30,-1,40,-1,-1,20,40,-1,30,-1,-1,-1};
    node*root=constructgt(v);
    //displaygt(root);
    //preordergt(root);
    //cout<<endl;
    root=flatten(root);
    displaygt(root);
   // cout<<mirror(root,root)<<endl;
   //linearise(root);
    //displaygt(root);


}