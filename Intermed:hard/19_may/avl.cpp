#include<iostream>
using namespace std;

class node
{
    public:
    int d;
    node*left;
    node*right;
    int height;
    int bal;
    node(int v)
    {
        this->d=v;
        this->left=nullptr;
        this->right=nullptr;
        this->height=0;
        this->bal=0;
    }
};

void printtree(node*root)
{
    if(root==NULL)
    {
        return;
    }
    string ls=root->left==NULL?".":to_string(root->left->d)+"["+to_string(root->left->bal)+","+to_string(root->left->height)+"]";
    string rs=root->right==NULL?".":to_string(root->right->d)+"["+to_string(root->right->bal)+","+to_string(root->right->height)+"]";
    string curr=to_string(root->d)+"["+to_string(root->bal)+","+to_string(root->height)+"]";
    cout<<ls<<"->"<<curr<<"<-"<<rs<<endl;
    printtree(root->left);
    printtree(root->right);
}

void update(node*&root)
{
    int lh=-1;
    int rh=-1;
    if(root->left!=nullptr)
    {
         lh=root->left->height;
    }
    if(root->right!=nullptr)
    {
        rh=root->right->height;
    }
    root->bal=lh-rh;
    root->height=max(lh,rh)+1;

}

node*leftrot(node*root)
{
    node*b=root->right;
    node*bkaleft=b->left;
    root->right=bkaleft;
    b->left=root;
    update(root);
    update(b);

    return b;

}

node*rightrot(node*root)
{
    node*b=root->left;
    node*bkaright=b->right;
    root->left=bkaright;
    b->right=root;
    update(root);
    update(b);
    return b;
}

node* checkbal(node*root)
{
    update(root);
    if(root->bal==2) //ll,lr
    {
        if(root->left->bal==1) //ll
        {
            return rightrot(root);
        }
        else  //lr
        {
            root->left=leftrot(root->left);
            return rightrot(root);
        }
        
    }
    else if(root->bal==-2)
    {
        if(root->right->bal==-1) //rr
        {
            return leftrot(root);
        }
        else  //rl
        {
            root->right=rightrot(root->right);
            return leftrot(root);
        }
    }
    return root;
}

node*addnode(node*root,int data)
{
    if(root==nullptr)
    {
        node*nn=new node(data);
        return checkbal(nn);
    }
    if(root->d>data)
    {
        root->left=addnode(root->left,data);
    }
    else
    {
        root->right=addnode(root->right,data);
    }
    return checkbal(root);
}

node*getnode(node*root)
{
    node*curr=root;
    while(curr->right!=nullptr)
    {
        curr=curr->right;
    }
    return curr;
}

node*deletenode(node*root,int data)
{
    if(root==nullptr)
    {
        cout<<"Not found"<<endl;
        return nullptr;
    }
    else if(root->d>data)
    {
        root->left=deletenode(root->left,data);
    }
    else if(root->d<data)
    {
        root->right=deletenode(root->right,data);
    }
    else
    {
        if(root->left==nullptr)
        {
            return root->right;
        }
        else if(root->right==nullptr)
        {
            return root->left;
        }
        else
        {
            node*exchnode=getnode(root->left);
            root->d=exchnode->d;
            return deletenode(root->left,exchnode->d);
        }
        
    }
    return checkbal(root);
    
}

int main(int argc,char**argv)
{
    node*root=nullptr;
    root=addnode(root,10);
    printtree(root);
    cout<<endl<<endl<<endl;
     root=addnode(root,20);
      printtree(root);
      cout<<endl<<endl<<endl;
      root=addnode(root,30);
       printtree(root);
       cout<<endl<<endl<<endl;
       root=addnode(root,40);
       printtree(root);
       cout<<endl<<endl<<endl;
       root=deletenode(root,10);
       printtree(root);
       cout<<endl<<endl<<endl;

}

// #include <iostream>
// #include <vector>

// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left = nullptr;  // Node* left=nullptr;
//     Node *right = nullptr; // Node* right=nullptr;

//     int height = 0;
//     int bal = 0;

//     Node(int data)
//     {
//         this->data = data;
//         this->height = 0;
//         this->bal = 0;
//     }

//     Node()
//     {
//     }
// };

// //AVL Util.========================================================

// void UpdateHeightAndBalance(Node *node) // O(1)
// {
//     int lh = -1;
//     int rh = -1;
//     if (node->left != nullptr)
//         lh = node->left->height;
//     if (node->right != nullptr)
//         rh = node->right->height;

//     node->height = max(lh, rh) + 1;
//     node->bal = lh - rh;
// }

// //ll rotation.
// Node *ll(Node *A) // O(1)
// {
//     Node *B = A->left;
//     Node *BkaRight = B->right;

//     B->right = A;
//     A->left = BkaRight;

//     UpdateHeightAndBalance(A);
//     UpdateHeightAndBalance(B);

//     return B;
// }

// //rr rotation.
// Node *rr(Node *A) // O(1)65
// {
//     Node *B = A->right;
//     Node *Bkaleft = B->left;

//     B->left = A;
//     A->right = Bkaleft;

//     UpdateHeightAndBalance(A);
//     UpdateHeightAndBalance(B);

//     return B;
// }

// //getRotation

// Node *getRotation(Node *node) //O(1)
// {
//     UpdateHeightAndBalance(node);
//     if (node->bal == 2) //ll,lr
//     {
//         if (node->left->bal == 1) // ll
//             return ll(node);
//         else //lr
//         {
//             node->left = rr(node->left);
//             return ll(node);
//         }
//     }
//     else if (node->bal == -2) // rr,rls
//     {

//         if (node->right->bal == -1) //rr
//             return rr(node);
//         else //rl
//         {
//             node->right = ll(node->right);
//             return rr(node);
//         }
//     }
//     return node;
// }

// //BST.===========================================================================

// Node *constructBST(vector<int> &arr, int si, int ei) // O(n) if sorted array.
// {
//     if (si > ei)
//         return nullptr;

//     int mid = (si + ei) >> 1; // (si+ei)/2;
//     Node *node = new Node(arr[mid]);
//     node->left = constructBST(arr, si, mid - 1);
//     node->right = constructBST(arr, mid + 1, ei);

//     UpdateHeightAndBalance(node);
//     return node;
// }

// void display(Node *node) // O(n)
// {
//     if (node == nullptr)
//         return;

//     string str = "";
//     str += ((node->left != nullptr) ? to_string(node->left->data) + "[" + to_string(node->left->bal) + "," + to_string(node->left->height) + "]" : ".");
//     str += " <- " + to_string(node->data) + "[" + to_string(node->bal) + "," + to_string(node->height) + "]" + " -> ";
//     str += ((node->right != nullptr) ? to_string(node->right->data) + "[" + to_string(node->right->bal) + "," + to_string(node->right->height) + "]" : ".");
//     cout << (str) << endl;

//     display(node->left);
//     display(node->right);
// }

// Node *addData(Node *root, int data) //O(logn)
// {
//     if (root == nullptr)
//         return new Node(data);
//     if (data < root->data)
//         root->left = addData(root->left, data);
//     else
//         root->right = addData(root->right, data);

//     return getRotation(root); //O(1)
// }

// int maximumEle(Node *node) // O(logn)
// {
//     Node *curr = node;
//     while (curr->right != nullptr)
//         curr = curr->right;

//     return curr->data;
// }

// Node *removeData(Node *root, int data) //O(logn)
// {
//     if (root == nullptr)
//         return nullptr; // never found data;

//     if (data < root->data)
//         root->left = removeData(root->left, data);
//     else if (data > root->data)
//         root->right = removeData(root->right, data);
//     else
//     { // data found.

//         if (root->left == nullptr || root->right == nullptr)
//             return root->left != nullptr ? root->left : root->right;

//         int maxInleft = maximumEle(root->left);
//         root->data = maxInleft;
//         root->left = removeData(root->left, maxInleft);
//     }
//     return getRotation(root); //O(1)
// }

// void solve()
// {
//     vector<int> arr = {100, 40, 20, 70, 30, 80, 10, 60, 90, 50, 130, 120, 110};
//     // Node *root = constructBST(arr, 0, arr.size() - 1);

//     Node *root = nullptr;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         root = addData(root, arr[i]);
//         display(root);
//         cout << endl<< endl<< endl;
//     }

//     display(root);
// }

// int main()
// {
//     solve();
//     return 0;
// }


