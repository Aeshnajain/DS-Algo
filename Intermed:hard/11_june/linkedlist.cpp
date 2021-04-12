#include<iostream>
using namespace std;

class ListNode
{
    public:
      int val;
      ListNode*next;
      ListNode(int v,ListNode*n)
      {
          this->val=v;
          this->next=n;
      }

};

ListNode*getmidUB(ListNode*head)
{
    ListNode*s=head;
    ListNode*f=head;
    while(f!=nullptr && f->next!=nullptr )
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

ListNode*getmidLB(ListNode*head)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    ListNode*s=head;
    ListNode*f=head;
    while(f->next!=nullptr && f->next->next!=nullptr)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

ListNode* reversePointersLL(ListNode*head)
{
    ListNode*curr=head;
    ListNode*prev=nullptr;
    ListNode*nex=nullptr;
    while(curr!=nullptr)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
    
}

void reverseDataLL(ListNode*head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return;
    }
    ListNode*mid=getmidLB(head);
    ListNode*nn=mid->next;
    mid->next=nullptr;
    nn=reversePointersLL(nn);
    ListNode*pn=nn;
    ListNode*curr=head;
    while(curr!=nullptr && nn!=nullptr)
    {
        int temp=curr->val;
        curr->val=nn->val;
        nn->val=temp;
        curr=curr->next;
        nn=nn->next;
    }
    nn=reversePointersLL(pn);
    mid->next=nn;
}

//lc 143
void reorderList(ListNode* head) 
{
    if(head==nullptr || head->next==nullptr)
    {
        return;
    }

    ListNode*s=head;
    ListNode*f=head;
    while(f->next!=nullptr && f->next->next!=nullptr)
    {
        s=s->next;
        f=f->next->next;
    }
    ListNode*nn=s->next;
    s->next=nullptr;
    ListNode*curr=nn;
    ListNode*prev=nullptr;
    ListNode*nex=nullptr;
    while(curr!=nullptr)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    nn=prev;
    curr=head;
    while(curr!=nullptr && nn!=nullptr)
    {
        ListNode*f1=curr->next;
        ListNode*f2=nn->next;
        curr->next=nn;
        nn->next=f1;
        curr=f1;
        nn=f2;
    }
    
        
}
int main(int argc,char**argv)
{
    //leetcode:206,876,19,143,203,83
    
     
}