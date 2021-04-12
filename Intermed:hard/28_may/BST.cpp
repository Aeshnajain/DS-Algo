#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
     int val;
     node*left=nullptr;
     node*right=nullptr;
     node(int v)
     {
         val=v;
     }
};
void display(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    string lv=root->left!=nullptr?to_string(root->left->val):".";
    string rv=root->right!=nullptr?to_string(root->right->val):".";
    cout<<lv<<"->"<<root->val<<"<-"<<rv<<endl;
    display(root->left);
    display(root->right);
}

node*constructBST(vector<int>&arr,int si,int ei)
{
    if(si>ei)
    {
        return nullptr;
    }
    int mid=(si+ei)/2;
    node*nn=new node(arr[mid]);
    nn->left=constructBST(arr,si,mid-1);
    nn->right=constructBST(arr,mid+1,ei);
    return nn;
}

int size(node*root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return size(root->left)+size(root->right)+1;
}

int height(node*root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int rv=height(root->left)>height(root->right)?height(root->left)+1:height(root->right)+1;
    return rv;
}

bool find(node*root,int d)
{
    node*curr=root;
    while(curr!=nullptr)
    {
        if(curr->val==d)
        {
            return true;
        }
        else if(curr->val>d)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
        
    }
    return false;
}

int maxele(node*root)
{
    node*curr=root;
    while(curr->right!=nullptr)
    {
        curr=curr->right;
    }
    return curr->val;
}


int minele(node*root)
{
    node*curr=root;
    while(curr->left!=nullptr)
    {
        curr=curr->left;
    }
    return curr->val;
}

 node* lowestCommonAncestor(node* root, node* p,node* q) 
 {
    node*rv=nullptr;
    if(root->val>p->val && root->val>q->val)
    {
        rv=lowestCommonAncestor(root->left,p,q);
    }
    else if(root->val<p->val && root->val<q->val)
    {
        rv=lowestCommonAncestor(root->right,p,q);
    }
    else
    {
        return root;
    }
    return rv;
}


//inorder
//range_in_increasing_order
void range01(node*root,int a,int b,vector<int>& ans)
{
    if(root==nullptr)
    {
        return;
    }
    range01(root->left,a,b,ans);
    if(root->val>=a && root->val<=b)
    {
        ans.push_back(root->val);
    }
    else if(root->val>b)
    {
        return;
    }
    range01(root->right,a,b,ans);
}


// isBST method1
// class Solution {
// public:
//     long maxleft(TreeNode*root)
//     {
//         if(root==NULL)
//         {
//              return LONG_MIN;
//         }
//         else
//         {
//             while(root->right!=NULL)
//             {
//                 root=root->right;
//             }
//         }
//         return root->val;
        
//     }
//     long minright(TreeNode*root)
//     {
//         if(root==NULL)
//         {
//              return LONG_MAX;
//         }
//         else
//         {
//             while(root->left!=NULL)
//             {
//                 root=root->left;
//             }
//         }
//         return root->val;
        
//     }
    
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL)
//         {
//             return true;
//         }
//         bool lv=isValidBST(root->left);
//         bool rv=isValidBST(root->right);
//         long maxl=maxleft(root->left);
//         long minr=minright(root->right);
//         cout<<maxl<<" "<<minr<<endl;
//         bool retv=root->val>maxl && root->val<minr?true:false;
//         return (lv&&rv&&retv);
//     }
// };
 
bool isBST(node*root,node*&prev)
{
    if(root==nullptr)
    {
        return true;
    }
    bool lv=isBST(root->left,prev);
    bool retv=true;
    
    if(prev!=nullptr)
    {
        retv=prev->val>=root->val?false:true;
    }
    prev=root;

    bool rv=isBST(root->right,prev);
    return lv && rv && retv;
    
}


//Leetcode 99: recover-binary-search-tree==========================

// TreeNode *a = nullptr;
// TreeNode *b = nullptr;
// TreeNode *c = nullptr; // previous.

// bool recoverTree_(TreeNode *root)
// {
//     if (root == nullptr)
//         return false;

//     if (recoverTree_(root->left))
//         return true;

//     if (c != nullptr && c->val > root->val)
//     {
//         b = root; // first time it may be wrong.
//         if (a == nullptr)
//             a = c; // a always br previous
//         else
//             return true;
//     }
    
//     c = root;  // set previous.

//     if (recoverTree_(root->right))
//         return true;

//     return false;
// }

// void recoverTree(TreeNode *root)
// {
//     recoverTree_(root);
//     if (a != nullptr)
//     {
//         int temp = a->val;
//         a->val = b->val;
//         b->val = temp;
//     }
// }

//inorder predecessor&successor
node*predBT=nullptr;
node*succBT=nullptr;
void predsuccBT(node*root,int d)
{
    if(root==nullptr)
    {
        return;
    }
    predsuccBT(root->left,d);
    if(root->val==d)
    {
        cout<<predBT->val<<endl;
    }
    if(predBT!=nullptr && predBT->val==d)
    {
        succBT=root;
    }
    predBT=root;
    predsuccBT(root->right,d);
}

void PredandSuccBST(node*root,int d)
{
    node*curr=root;
    node*pred=nullptr;
    node*succ=nullptr;
    while(curr!=nullptr)
    {
        if(curr->val>d)
        {
            succ=curr;
            curr=curr->left;
        }
        else if(curr->val<d)
        {
            pred=curr;
            curr=curr->right;
        }
        else
        {
            if(curr->left==nullptr)
            {
                cout<<"PREDECESSOR"<<(pred==nullptr?-1:pred->val)<<endl;
            }
            else
            {
                pred=curr->left;
                while(pred->right!=nullptr)
                {
                    pred=pred->right;
                }
                 cout<<"PREDECESSOR"<<pred->val<<endl;
            }

            if(curr->right==nullptr)
            {
                cout<<"SUCCESSOR"<<(succ==nullptr?-1:succ->val)<<endl;
            }
            else
            {
                succ=curr->right;
                while(succ->left!=nullptr)
                {
                    succ=succ->left;
                }
                 cout<<"SUCCESSOR"<<succ->val<<endl;
            }
            
        }
        
    }

}

node*constructBSTusingPreorder(vector<int>&preorder,int lb,int rb,int&idx)
{
    if(idx==preorder.size()||preorder[idx]<lb||preorder[idx]>rb)
    {
        return nullptr;
    }
    node*nn=new node(preorder[idx]);
    idx++;
    nn->left=constructBSTusingPreorder(preorder,lb,nn->val,idx);
    nn->right=constructBSTusingPreorder(preorder,nn->val,rb,idx);
    return nn;
}

int getheight(vector<int>&preorder,int lb,int rb,int&idx)
{
    if(idx==preorder.size()||preorder[idx]<lb||preorder[idx]>rb)
    {
        return -1;
    }
    int ele=preorder[idx];
    idx++;
    int lv=getheight(preorder,lb,ele,idx);
    int rv=getheight(preorder,ele,rb,idx);
    return lv>rv?lv+1:rv+1;

}


node*addBST(node*root,int d)
{
    if(root==nullptr)
    {
        node*nn=new node(d);
        return nn;
    }
    if(root->val>d)
    {
        root->left=addBST(root->left,d);
    }
    else
    {
       root->right=addBST(root->right,d);
    }
    return root;
    
}

node*removeBST(node*root,int d)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(d<root->val)
    {
       root->left=removeBST(root->left,d);
    }
    else if(d>root->val)
    {
       root->right=removeBST(root->right,d);
    }
    else
    {
        if(root->right==nullptr || root->left==nullptr)
        {
            return root->left==nullptr?root->right:root->left;
        }
        else
        {
            int max=maxele(root->left);
            root->val=max;
            root->left=removeBST(root->left,max);
        }
        
    }
    return root;
    
}

int main(int argc,char**argv)
{
    vector<int> arr {10,20,30,40,50,60,70,80,90};
    node*root=constructBST(arr,0,arr.size()-1);
    display(root);
    cout<<endl;
    // cout<<find(root,180)<<endl;
    // cout<<maxele(root)<<" "<<minele(root)<<endl;
    // vector<int> ans;
    // range01(root,40,80,ans);
    // for(int a:ans)
    //  cout<<a<<" ";
    // cout<<endl;
    root=removeBST(root,20);
    display(root);
}