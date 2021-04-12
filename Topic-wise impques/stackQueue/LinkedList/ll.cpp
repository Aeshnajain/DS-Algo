#include<iostream>

using namespace std;

class node
{
    public:
    int data=0;
    node*next=nullptr;
    node(int d)
    {
        this->data=d;
    }

};

node*middle(node*head)
{
    node*f=head;
    node*s=head;
    while(f!=nullptr && f->next!=nullptr)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}
node*midnode(node*head)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    node*f=head;
    node*s=head;
    while(f->next!=nullptr && f->next->next!=nullptr)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}
node*reversell(node*head)
{
    node*curr=head;
    node*prev=nullptr;
    while(curr!=nullptr)
    {
        node*forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}

node*midnode(node*head)
{
    node*s=head;
    node*f=head;
    while(f->next!=nullptr && f->next->next!=nullptr)
    {
        f=f->next->next;
        s=s->next;
    }
    return s;
}
node*mergelist(node*l1,node*l2)
{
    if(l2==nullptr)
    {
        return l1;
    }
    if(l1==nullptr)
    {
        return l2;
    }
    node*newh=nullptr;
    node*move=nullptr;
    while(l1!=nullptr && l2!=nullptr)
    {
        if(l1->data<l2->data)
        {
            if(move==nullptr)
            {
                move=l1;
                newh=l1;
            }
            else
            {
                move->next=l1;
                move=move->next;
            }
            l1=l1->next;
            
        }
        else 
        {
            if(move==nullptr)
            {
                move=l2;
                newh=l2;
            }
            else
            {
                move->next=l2;
                move=move->next;
            }
            l2=l2->next;
            
        }
    }
    if(l1!=nullptr)
    {
        move->next=l1;
    }
    if(l2!=nullptr)
    {
        move->next=l2;
    }
    
    return newh;
}
    
node* sortList(node* head) {
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    node*mn=midnode(head);
    node*nhead=mn->next;
    mn->next=nullptr;
    
    node*s1=sortList(head);
    node*s2=sortList(nhead);
    return mergelist(s1,s2);
}

int main(int argc,char**argv)
{
    node*head=new node(10);

}