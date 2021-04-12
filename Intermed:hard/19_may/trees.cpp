#include<iostream>
#include<vector>
#include<queue>


using namespace std;

class node
{
    public:
      int d;
      node*left=NULL;
      node*right=NULL;
      node(int data)
      {
          this->d=data;
      }
};

node* constructtree(vector<int> arr,int& idx)
{
    if(idx>=arr.size() || arr[idx]==-1)
    {
        idx++;
        return NULL;
    }
     node*nn=new node(arr[idx]);
     idx=idx+1;
     nn->left=constructtree(arr,idx);
     //idx=idx+1;
     nn->right=constructtree(arr,idx);
     return nn;
}

void printtree(node*root)
{
    if(root==NULL)
    {
        return;
    }
    string ls=root->left==NULL?".":to_string(root->left->d);
    string rs=root->right==NULL?".":to_string(root->right->d);
    cout<<ls<<"->"<<root->d<<"<-"<<rs<<endl;
    printtree(root->left);
    printtree(root->right);
}

int size(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return (size(root->left)+size(root->right)+1);
}

int height(node*root)
{
    if(root==NULL)
    {
        return -1;//in terms of edge count
        //return 0 in terms of node count
    }
    int max=height(root->left)>height(root->right)?height(root->left)+1:height(root->right)+1;
    return max;
}

int max(node*root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    int tmax=max(root->left)>max(root->right)?max(root->left):max(root->right);
    int mmax=tmax>root->d?tmax:root->d;
    return mmax;
}
int min(node*root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    int tmin=min(root->left)<min(root->right)?min(root->left):min(root->right);
    int mmin=tmin<root->d?tmin:root->d;
    return mmin;
}

bool find(node*root,int val)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->d==val)
    {
        return true;
    }
    return (find(root->left,val) || find(root->right,val));
}

//****************TRAVERSAL************************

void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->d<<" ";
    preorder(root->left);
     preorder(root->right);
}

void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->d<<" ";
     inorder(root->right);
}

void postorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->d<<" ";
}

//****************************************************

bool nodetorootpath(node*root,int val,vector<node*>&ans)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->d==val)
    {
        ans.push_back(root);
        return true;
    }
    if(nodetorootpath(root->left,val,ans) || nodetorootpath(root->right,val,ans))
    {
        ans.push_back(root);
        return true;
    }
    return false;
    
}

vector<node*> nodetorootpath2(node*root,int val)
{
    if(root==NULL)
    {
        vector<node*> v;
        return v;
    }
    if(root->d==val)
    {
        vector<node*> v;
        v.push_back(root);
        return v;
    }
    vector<node*> vl=nodetorootpath2(root->left,val);
    if(vl.size()!=0)
    {
        vl.push_back(root);
        return vl;
    }
    vector<node*> vr=nodetorootpath2(root->right,val);
    if(vr.size()!=0)
    {
        vr.push_back(root);
        return vr;
    }
    vector<node*> v;
    return v;
}

//LC236 LCA1*****************************************
node*LCA=NULL;
bool LCA2(node*root,int p,int q)
{
    if(root==NULL)
    {
        return false;
    }
    bool selfdone=((root->d==p)||(root->d==q))?true:false;
    bool leftdone=LCA2(root->left,p,q);
    if(LCA!=NULL)
    {
        return true;
    }
    bool rightdone=LCA2(root->right,p,q);
    if(LCA!=NULL)
    {
        return true;
    }
    if((selfdone&&leftdone) || (selfdone&&rightdone) || (leftdone&&rightdone) )
    {
        LCA=root;
    }

    return (selfdone||leftdone||rightdone);



}

void kdown(node*root,int level,node*block)
{
    if(root==NULL || root==block)
    {
        return;
    }
    if(level==0)
    {
        cout<<root->d<<" "<<endl;
        return;
    }
    kdown(root->left,level-1,block);
    kdown(root->right,level-1,block);
}

void kdistaway(node*root,int target,int k)
{
    vector<node*> v;
    nodetorootpath(root,target,v);
    node*block=NULL;
    for(int i=0;i<v.size();i++)
    {
        if(k-i>=0)
        {
            kdown(v[i],k-i,block);
            block=v[i];
        }
    }

}


int kdistaway2(node*root,int val,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->d==val)
    {
        kdown(root,k,NULL);
        return 1;
    }
    int leftval=kdistaway2(root->left,val,k);
    if(leftval!=-1)
    {
        if(k-leftval>=0)
        {
            kdown(root,k-leftval,root->left);
        }
        return leftval+1;
    }
    int rightval=kdistaway2(root->right,val,k);
    if(rightval!=-1)
    {
        if(k-rightval>=0)
        {
            kdown(root,k-rightval,root->right);
        }
        return rightval+1;
    }
    return -1;
    
}

void kdown2(node*root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==0)
    {
        cout<<root->d<<" "<<endl;
        return;
    }
    kdown2(root->left,level-1);
    kdown2(root->right,level-1);
}



int kdistaway3(node*root,int val,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->d==val)
    {
        kdown2(root,k);
        return 1;
    }
    int leftval=kdistaway3(root->left,val,k);
    if(leftval!=-1)
    {
        if(k-leftval==0)
        {
            cout<<root->d<<" "<<endl;
            return -1;
        }
        else if(k-leftval>0)
        {
            kdown2(root->right,k-leftval-1);
            /* code */
        }
        
        return leftval+1;
    }
    int rightval=kdistaway2(root->right,val,k);
    if(rightval!=-1)
    {
        if(k-rightval==0)
        {
            cout<<root->d<<" "<<endl;
            return -1;
        }
        else if(k-rightval>0)
        {
            kdown2(root->left,k-rightval-1);
            /* code */
        }
        
        return rightval+1;
    }
    return -1;
    
}

int diameter(node*root,int&ans)
{
    if(root==NULL)
    {
        return -1;
    }
    
    int la=diameter(root->left,ans);
    int ra=diameter(root->right,ans);
    int tv=la+ra+2;
    if(tv>ans)
    {
        ans=tv;
    }
    int rv=la>ra?la+1:ra+1;
    return rv;
}

//LC-112,113,1123 leaf2leafpath(gfgs)*************************


int leaf2leafmaxsumans=INT_MIN;
int leaf2leafmaxsum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lv=leaf2leafmaxsum(root->left);
    int rv=leaf2leafmaxsum(root->right);
    if(root->left!=NULL && root->right!=NULL)
    {
        if(lv+rv+root->d>leaf2leafmaxsumans)
       {
           leaf2leafmaxsumans=lv+rv+root->d;
       }
       int retv=lv>rv?lv+root->d:rv+root->d;
       return retv;
    }
   return (root->left==NULL?rv+root->d:lv+root->d);

}
int maxPathSum(node *root) {
    leaf2leafmaxsumans=INT_MIN;
    leaf2leafmaxsum(root);
    return leaf2leafmaxsumans;
    // code here
}


//levelorder

void levelorder01(node*root)//using 2 queues
{
    queue<node*> pq;
    queue<node*> cq;
    pq.push(root);
    int count=0;
    cout<<"Level:"<<count<<" ";
    while(pq.size()!=0)
    {
        node*t=pq.front();
        pq.pop();
        cout<<t->d<<" ";
        if(t->left!=NULL)
        {
            cq.push(t->left);
        }
        if(t->right!=NULL)
        {
            cq.push(t->right);
        }
        if(pq.size()==0)
        {
            queue<node*> temp=pq;
            pq=cq;
            cq=temp;
             count++;
             if(pq.size()!=0)
             {
                cout<<endl;
                cout<<"Level:"<<count<<" ";
             }
           
        }
    }
    cout<<endl;

}

void levelorder02(node*root)
{
    queue<node*> pq;
    pq.push(root);
    pq.push(NULL);
    int count=0;
    cout<<"Level:"<<count<<" ";
    while(pq.size()!=1)
    {
        node*t=pq.front();
        pq.pop();
       cout<<t->d<<" ";
       if(t->left!=NULL)
        {
            pq.push(t->left);
        }
        if(t->right!=NULL)
        {
            pq.push(t->right);
        }
        if(pq.front()==NULL)
        {
            pq.pop();
            pq.push(NULL);
            count++;
            if(pq.size()!=1)
             {
                cout<<endl;
                cout<<"Level:"<<count<<" ";
             }
        }

    }
    cout<<endl;

}


void levelorder3(node*root)
{
    queue<node*> pq;
    pq.push(root);
    int count=0;
    while(pq.size()!=0)
    {
        int it2=pq.size();
        cout<<"Level:"<<count<<" ";
        for(int i=0;i<it2;i++)
        {
            node*t=pq.front();
            pq.pop();
            cout<<t->d<<" ";
            if(t->left!=NULL)
            {
                pq.push(t->left);
            }
            if(t->right!=NULL)
            {
                pq.push(t->right);
            }
        }
        cout<<endl;
        count++;
    }
}

//Views****************************************************

void leftview(node*root)
{
    queue<node*> pq;
    pq.push(root);
    while(pq.size()!=0)
    {
        int itr=pq.size();
        node*t=pq.front();
        cout<<t->d<<" ";
        for(int i=0;i<itr;i++)
        {
            node*t=pq.front();
            pq.pop();
            if(t->left!=NULL)
            {
                pq.push(t->left);
            }
            if(t->right!=NULL)
            {
                pq.push(t->right);
            }

        }
       
    }
     cout<<endl;
}


void rightview(node*root)
{
    queue<node*> pq;
    pq.push(root);
    while(pq.size()!=0)
    {
        int itr=pq.size();
        node*prev=NULL;
        for(int i=0;i<itr;i++)
        {
            node*t=pq.front();
            pq.pop();
            if(t->left!=NULL)
            {
                pq.push(t->left);
            }
            if(t->right!=NULL)
            {
                pq.push(t->right);
            }
            prev=t;
        }
        cout<<prev->d<<" ";
       
    }
     cout<<endl;
}
int minwidth=0;
int maxwidth=0;

void width(node*root,int level)
{
    if(root==NULL)
    {
        return;
    }
    minwidth=minwidth<level?minwidth:level;
    maxwidth=maxwidth>level?maxwidth:level;
    width(root->left,level-1);
    width(root->right,level+1);
}

class mypair
{
    public:
        node* nn;
        int lvl;
        mypair(node*n,int l)
        {
            this->nn=n;
            this->lvl=l;
        }

};

//vertical order

void vertical(node*root)
{
    width(root,0);
    int s=maxwidth-minwidth+1;
    vector<vector<int> > ans(s,vector<int>());
    
    queue<mypair> pq;
    mypair p1(root,-minwidth);
    pq.push(p1);
    while(pq.size()!=0)
    {
        mypair t=pq.front();
        pq.pop();
        ans[t.lvl].push_back(t.nn->d);
        if(t.nn->left!=NULL)
        {
            mypair lp(t.nn->left,t.lvl-1);
            pq.push(lp);
        }
        if(t.nn->right!=NULL)
        {
            mypair rp(t.nn->right,t.lvl+1);
            pq.push(rp);
        }

    }
    for(vector<int> v1:ans)
    {
       for(int i:v1)
       {
           cout<<i<<" ";
       }
       cout<<endl;
    }
    
}

void bottomview(node*root)
{
    width(root,0);
    vector<int> ans (maxwidth-minwidth+1,0);
    queue<mypair> pq;
    mypair p1(root,-minwidth);
    pq.push(p1);
    while(pq.size()!=0)
    {
        mypair t=pq.front();
        pq.pop();
        ans[t.lvl]=t.nn->d;
        if(t.nn->left!=NULL)
        {
            mypair lp(t.nn->left,t.lvl-1);
            pq.push(lp);
        }
        if(t.nn->right!=NULL)
        {
            mypair rp(t.nn->right,t.lvl+1);
            pq.push(rp);
        }
    }
    for(int v:ans)
    {
        cout<<v<<" ";
    }
    cout<<endl;

}

void topview(node*root)
{
    width(root,0);
    vector<int> ans (maxwidth-minwidth+1,INT_MIN);
    
    queue<mypair> pq;
    mypair p1(root,-minwidth);
    pq.push(p1);
    while(pq.size()!=0)
    {
        mypair t=pq.front();
        pq.pop();
        if(ans[t.lvl]==INT_MIN)
        {
            ans[t.lvl]=t.nn->d;
        }
        if(t.nn->left!=NULL)
        {
            mypair lp(t.nn->left,t.lvl-1);
            pq.push(lp);
        }
        if(t.nn->right!=NULL)
        {
            mypair rp(t.nn->right,t.lvl+1);
            pq.push(rp);
        }
    }
    for(int v:ans)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}
int minwidth1=0;
int maxwidth1=0;

void width2(node*root,int level)
{
    if(root==NULL)
    {
        return;
    }
    minwidth1=minwidth1<level?minwidth1:level;
    maxwidth1=maxwidth1>level?maxwidth1:level;
    width2(root->left,level-1);
    width2(root->right,level+0);
}

void diagnolview(node*root)
{
    width2(root,0);
    vector<int> a;
    vector<vector<int>> ans (-minwidth1+1,a);

    queue<mypair> pq;
    mypair p1(root,-minwidth1);
    pq.push(p1);
    while(pq.size()!=0)
    {
        mypair t=pq.front();
        pq.pop();
        ans[t.lvl].push_back(t.nn->d);
        if(t.nn->left!=NULL)
        {
            mypair lp(t.nn->left,t.lvl-1);
            pq.push(lp);
        }
        if(t.nn->right!=NULL)
        {
            mypair rp(t.nn->right,t.lvl+0);
            pq.push(rp);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int a:ans[i])
        {
          cout<<a<<" ";
        }
        cout<<endl;
    }

}

void diagnolview2(node*root)
{
    vector<vector<int>> ans;
    vector<int> midans;
    queue<node*> ri;
    queue<node*> le;
    ri.push(root);
    while(ri.size()!=0)
    {
        node*t=ri.front();
        ri.pop();
        //cout<<t->d<<" ";
        midans.push_back(t->d);
        if(t->left!=NULL)
        {
            le.push(t->left);
        }
        if(t->right!=NULL)
        {
            ri.push(t->right);
        }
        if(ri.size()==0) 
        {
            queue<node*>temp=ri;
            ri=le;
            le=temp;
            ans.push_back(midans);
            midans.clear();
        }
        
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int a:ans[i])
        {
          cout<<a<<" ";
        }
        cout<<endl;
    }
}

//leetcode 987**********************

//conversionindoublylinkedlist

node*DLLhead=NULL;
node*DLLlast=NULL;

void convertinDLL(node*root)
{
    if(root==NULL)
    {
        return;
    }
    convertinDLL(root->left);
    if(DLLhead==NULL)
    {
        DLLhead=root;
    }
    else
    {
        DLLlast->right=root;
        root->left=DLLlast;
    }
    DLLlast=root;
    convertinDLL(root->right);
    
}

int main(int argc,char**argv)
{
    vector<int> arr {10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1};
    int idx=0;
    node*root=NULL;
    root=constructtree(arr,idx);
    printtree(root);
    // cout<<size(root)<<endl;
    // cout<<height(root)<<endl;
    // cout<<max(root)<<endl;
    // cout<<min(root)<<endl;
    // cout<<find(root,900)<<endl;
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    //  cout<<endl;
    // postorder(root);
    //  cout<<endl;
    //  vector<node*> ans;
    //  //nodetorootpath(root,120,ans);
    //  for(int i=0;i<ans.size();i++)
    //  {
    //      cout<<ans[i]->d<<" ";
    //  }
    //  cout<<endl;
    //  ans=nodetorootpath2(root,120);
    //  for(int i=0;i<ans.size();i++)
    //  {
    //      cout<<ans[i]->d<<" ";
    //  }
    // cout<<endl;

    //LCA2(root,40,140);
    //int ans=LCA!=NULL?LCA->d:-1;
    //cout<<ans<<endl;

    //kdistaway(root,50,1);
    //kdistaway2(root,50,1);
    //kdistaway3(root,50,2);
    // leaf2leafmaxsum(root);
    // cout<<leaf2leafmaxsumans<<endl;
    // levelorder01(root);
    // levelorder02(root);
    // levelorder3(root);
   // leftview(root);
    //rightview(root);
   // vertical(root);
   //topview(root);
   //bottomview(root);
   diagnolview(root);
   diagnolview2(root);

   convertinDLL(root);
   node*temp=DLLhead;
   while(temp!=NULL)
   {
       cout<<temp->d<<" ";
       temp=temp->right;
   }
   cout<<endl;


}