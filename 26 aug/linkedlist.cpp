#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;

    node()
    {
        data=0;
        next=NULL;
    }

    node(int data,node* next)
    {
        this->data=data;
        this->next=next;
    }

};

void addlast(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        head=tail=new node(d,NULL);
    }
    else
    {
        node* nn=new node(d,NULL);
        tail->next=nn;
        tail=nn;
        
    }
    
}

void display(node* head)
{
    for(node* i=head;i!=NULL;i=i->next)
    {
        cout<<i->data<<" ";
    }
    cout<<endl;

}

int size(node* head)
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;

}

void addfirst(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        head=tail=new node(d,NULL);
    }
    else
    {
        node* nn=new node(d,head);
        head=nn;
        
    }
    
}

int getfirst(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return head->data;
    }
    
}

int getlast(node* tail)
{
    if(tail==NULL)
    {
        return 0;
    }
    else
    {
        /* code */
        return tail->data;
    }
    
}

int getat(node* head,int idx)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        int j=0;
        for(node* i=head;i!=NULL;i=i->next)
        {
            if(j==idx)
            {
                return i->data;
            }
            j++;
        }
        /* code */
    }
    return 0;
    
}

node* getnode(node* head,int idx)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        int j=0;
        for(node* i=head;i!=NULL;i=i->next)
        {
            if(j==idx)
            {
                return i;
            }
            j++;
        }
        /* code */
    }
    return NULL;

}

void addat(node*& head,node*& tail,int d,int idx)
{
    int sz=size(head);
    if(idx<0 || idx>sz)
    {
        cout<<"invalid index"<<endl;
    }
    else if(idx==0)
    {
        addfirst(head,tail,d);
    }
    else if(idx==sz)
    {
        addlast(head,tail,d);
    }
    else
    {
        node* prev=getnode(head,idx-1);
        prev->next=new node(d,prev->next);
    }


}

void remfirst(node*&head,node*&tail)
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        node* temp=head;
        head=tail=NULL;
        delete temp;
    }
    else 
    {
        node* temp=head->next;
        delete head;
        head=temp;

    }
    
}

void remlast(node*&head,node*&tail)
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        node* temp=head;
        head=tail=NULL;
        delete temp;
    }
    else
    {
        int sz=size(head);
        node* prev=getnode(head,sz-2);

        delete tail;
        prev->next=NULL;
        tail=prev;
        


    }
    
    
    
}

void remat(node*&head,node*&tail,int idx)
{
    int sz=size(head);
    if(idx<0 || idx>=sz)
    {
        cout<<"invalid index"<<endl;
    }
    else if(idx==0)
    {
        remfirst(head,tail);

    }
    else if(idx==sz-1)
    {
        remlast(head,tail);
    }
    else
    {
        node*prev=getnode(head,idx-1);
        node* temp=prev->next;
        prev->next=prev->next->next;
        delete temp;
    }
    
}

void reversedi(node*head,node*tail) //reverse data n^2
{
    int sz=size(head)-1;
    int left=0;
    
    while(left<sz)
    {
        node*l=getnode(head,left);
        node*r=getnode(head,sz);
        int temp=l->data;
        l->data=r->data;
        r->data=temp;
        left++;
        sz--;
    }
}


void reversepi(node*&head,node*&tail)
{
    node* prev=NULL;
    node* curr=head;

    while(curr!=NULL)
    {
        node* upnext=curr->next;

        curr->next=prev;
        prev=curr;
        curr=upnext;

    }

    node* temp=head;
    head=tail;
    tail=temp;
}

void displayreverserecursive(node* head) //displaying_the_reverse_linkedlist 
{
    if(head==NULL)
    {
        return;
    }
    displayreverserecursive( head->next);
    cout<<head->data<<" ";

}
int temp=0;

void revprec(node*&head,node* n,int sz) //reversing_the_data_of_linkedlist_using_recursion
{
    if(n==NULL)
    {
        return;
    }
    
    revprec(head,n->next,sz);
    if(temp<sz/2)
    {
        node*val=head->next;
        int v=head->data;
        head->data=n->data;
        n->data=v;
        head=val;

        temp++;
    }


}


void revprec2(node*&left,node* right,int f,int& sz)
{
    if(right==NULL)
    {
        return;
    }

    sz++;
    revprec2(left,right->next,f+1,sz);
    if(f>=sz/2)
    {
        int v=left->data;
        left->data=right->data;
        right->data=v;
        left=left->next;
    }


}

bool ispalindrome(node*&left,node*right,int& sz)
{
    if(right==NULL)
    {
        return true;
    }
    sz++;
    bool s=ispalindrome(left,right->next,sz);
    if(sz>=0)
    {
        if(s==false)
        {
            return false;
        }
        else
        {
            int d=left->data;
            left=left->next;
            if(d==right->data)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        sz=sz-2;
    }
    else
    {
       return true;
    }
    
    
}

bool ispalindrome2(node*&left,node*right)
{
    if(right==NULL)
    {
        return true;
    }
    bool res=ispalindrome2(left,right->next);
    res=res && left->data==right->data;
    left=left->next;
    return res;
}

void fold(node* &left,node*right,int f,int& sz,node*&tail)
{
    if(right==NULL)
    {
        return;
    }
    sz++;
    fold(left,right->next,f+1,sz,tail);
    if(f>sz/2)
    {
        node*temp=left->next;
        left->next=right;
        right->next=temp;
        left=temp;
    }
    else if(f==sz/2)
    {
        tail=right;
        tail->next=NULL;
    }

}



int midrec(node*o1,node*o2) //midusing recursion
{
    if(o2->next==NULL || o2->next->next==NULL)
    {
        return o1->data;
    }
    
    int m=midrec(o1->next,o2->next->next);
    return m;
    
}

int mid(node*head)
{
    node*s=head;
    node*f=head;

    while(f->next!=NULL && f->next->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    return s->data;
}

node*krevhelp(node*nt1,int k)
{
    node*prev=NULL;
    node*curr=nt1;

    for(int i=0;i<k;i++)
    {
        node*n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }

    nt1->next=curr;
    return prev;
}

void krev(node*&head,node*&tail,int k)
{
    int sz=size(head);
    if(sz<k)
    {
        return;
    }
    int counter=0;
    node*t1=head;
    node*t2=krevhelp(t1,k);
    head=t2;
    counter+=k;

    while(sz-counter>=k)
    {
        node*nt1=t1->next;
        node*nt2=krevhelp(nt1,k);
        t1->next=nt2;
        t1=nt1;

        counter+=k;
    }
    if(counter==sz)
    {
        tail=t1;
    }
}

int kfromlast(node*head,int k) //slow_travels_size-k_distance
{
    node*f=head;
    node*s=head;
    for(int i=0;i<k;i++)
    {
        f=f->next;
    }

    while(f!=NULL)
    {
        s=s->next;
        f=f->next;
    }

    return s->data;

}

void krev2(node*&head,node*&tail,int k)
{
    int sz=size(head);
    if(sz<k)
    {
        return;
    }
    node*ph=NULL;
    node*pt=NULL;

    while(head!=NULL && sz>=k)
    {
        node*ch=NULL;
        node*ct=NULL;
        for(int i=0;i<k;i++)
        {
            int h=head->data;
            remfirst(head,tail);
            addfirst(ch,ct,h);
            sz--;
        }
        if(ph==NULL)
        {
            ph=ch;
            pt=ct;
        }
        else
        {
            pt->next=ch;
            pt=ct;
        }
        

    }

    if(head==NULL)
    {
        tail=pt;
    }
    else
    {
        pt->next=head;
    }
    
    head=ph;
    


}

void oddeven(node*&head,node*&tail)
{
    node*oh=NULL;
    node*ot=NULL;

    node*eh=NULL;
    node*et=NULL;

    while(head!=NULL)
    {
        if(head->data%2==0)
        {
            addlast(eh,et,head->data);
            remfirst(head,tail);
        
        }
        else 
        {
            addlast(oh,ot,head->data);
            remfirst(head,tail);
        }
        

    }

    if(oh!=NULL && eh!=NULL)
    {
        ot->next=eh;
        head=oh;
        tail=et;
    }
    else if(oh!=NULL)
    {
        head=oh;
        tail=ot;

    }
    else if(eh!=NULL)
    {
        head=eh;
        tail=et;
    }
    else
    {
        head=NULL;
        tail=NULL;
    }
    
}

void duplicacy(node*&head,node*&tail)
{
    node*nh=NULL;
    node*nt=NULL;

    while(head!=NULL)
    {
        int h=head->data;
        remfirst(head,tail);

        if(nh==NULL || nt->data!=h)
        {
            addlast(nh,nt,h);
        }
    }
    head=nh;
    tail=nt;
}

node* unfold(node*f,node*s,node*&tail)
{
    if(f->next==NULL)
    {
        f->next=s;
        return s;
    }
    else if(f->next->next==NULL)
    {
         f->next->next=s;
         return s;
    }
    node*n=f->next;
    f->next=f->next->next;
    node* r=unfold(f->next,n,tail);
    r->next=s;

    if(s==NULL)
    {
        tail=r;
    }

    return s;
    



}

// void floyd(node*head)
// {
//     node*s=head;
//     node*f=head;

//     while(s->next!=f->next)
//     {
//         f=f->next->next;
//         s=s->next;

//         if(f->next==NULL || f==NULL)
//         {
//             cout<<"false";
//             return;
//         }

//     }
//     s=s->next;
//     f=head;

//     while(s->next!=f)
//     {
//         f=f->next;
//         s=s->next;
//     }
//     s->next=NULL;


// }


void floyd(node*head)
{
    node*s=head;
    node*f=head;

    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;

        if(s==f)
        {
            cout<<"loop found"<<endl;
            f=head; 
            if(s==head) //only_loop
            {
                while(s->next!=head)
                {
                   s=s->next;
                }
            }
            else
            {
                while(f->next!=s->next)
                {
                   f=f->next;
                   s=s->next;
                }
            

            }
            s->next=NULL;
            break;
        }
    }

}

void mergesl(node*h1,node*h2,node*&oh,node*&ot)
{
    node*m1=h1;
    node*m2=h2;

    while(m1!=NULL || m2!=NULL)
    {
        if(m1==NULL)
        {
            addlast(oh,ot,m2->data);
            m2=m2->next;
        }
        else if(m2==NULL)
        {
            addlast(oh,ot,m1->data);
            m1=m1->next;
        }
        else 
        {
                if(m1->data<m2->data)
            {
                addlast(oh,ot,m1->data);
                m1=m1->next;
            }
            else
            {
                addlast(oh,ot,m2->data);
                m2=m2->next;
            }
        }
        
    }

}

node* midnode(node*head,node*tail)
{
    node*s=head;
    node*f=head;

    while(f!=tail && f->next!=tail)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}


void mergesort(node*&head,node*&tail)
{
    if(head==tail)
    {
        //through this the original list remains intact and new nodes are formed
        //giving rise to new list which further leads to memory leak.
        node*nn=new node(head->data,NULL);
        head=tail=nn;
        return;
    }
    node*mid=midnode(head,tail);
    //the variables lh,lt,rh and rt puts us in the position of memory leak as
    //memory used isn't deleted and is neither used.

    node*lh=head;
    node*lt=mid;
    node*rh=mid->next;
    node*rt=tail;

    mergesort(lh,lt);
    mergesort(rh,rt);

    node*fh=NULL;
    node*ft=NULL;

    mergesl(lh,rh,fh,ft);
    head=fh;
    tail=ft;


}

void inplacemergesl(node*lh,node*lt,node*rh,node*rt,node*&oh,node*&ot)
{
    node*m1=lh;
    node*m2=rh;

    while(m1!=NULL && m2!=NULL)
    {
        node*rem;
        if(m1->data<m2->data)
        {
            rem=m1;
            m1=m1->next;
            rem->next=NULL;
        }
        else
        {
            rem=m2;
            m2=m2->next;
            rem->next=NULL;
        }

        if(oh==NULL)
        {
            oh=ot=rem;
        }
        else
        {
            ot->next=rem;
            ot=rem;
        }
        
        
    }
    if(m1!=NULL)
    {
        ot->next=m1;
        ot=lt;
    }
    else
    {
        ot->next=m2;
        ot=rt;
        
    }
    
}

void inplacemergesort(node*&head,node*&tail)
{
    if(head==tail)
    {
        return;
    }
    node*mid=midnode(head,tail);

    node*lh=head;
    node*lt=mid;
    node*rh=mid->next;
    node*rt=tail;
    
    mid->next=NULL;
    inplacemergesort(lh,lt);
    inplacemergesort(rh,rt);

    node*fh=NULL;
    node*ft=NULL;

    inplacemergesl(lh,lt,rh,rt,fh,ft);
    head=fh;
    tail=ft;

}

// bool checkpalindrome(node*head)
// {
//     if(head==nullptr)
//     {
//         return false;
//     }
//     node*s=head;
//     node*f=head;
//     while(f->next!=nullptr && f->next->next!=nullptr)
//     {
//         s=s->next;
//         f=f->next->next;
//     }
//     node*nh=s->next;
//     s->next=nullptr;
//     node*prev=nullptr;
//     node*curr=nh;
//     while(curr!=nullptr)
//     {
//         node*upnext=curr->next;
//         curr->next=prev;
//         prev=curr;
//         if(upnext==nullptr)
//         {
//             nh=curr;
//         }
//         curr=upnext;
        
//     }
//     while(nh!=nullptr && head!=nullptr)
//     {
//         if(nh->data!=head->data)
//         {
//             return false;
//         }
//         nh=nh->next;
//         head=head->next;
//     }
//     return true;
// }



int main(int args,char** argv)
{
    node* head=NULL;
    node* tail=NULL;
    // addat(head,tail,100,0);
    // remfirst(head,tail);
    // addfirst(head,tail,70);
    // remlast(head,tail);
    // addlast(head,tail,10);
    // addlast(head,tail,20);
    // addlast(head,tail,30);
    // remat(head,tail,2);
    // addlast(head,tail,40);
    // addlast(head,tail,50);
    // addfirst(head,tail,60);
    // addat(head,tail,1000,8);
    // addat(head,tail,200,3);
    // remfirst(head,tail);
    // remlast(head,tail);
    // remat(head,tail,3);
    //display(head);
    //addfirst(head,tail,100);
    addfirst(head,tail,30);
    addfirst(head,tail,50);
    addfirst(head,tail,50);
    addfirst(head,tail,30);


    //reversepi(head,tail);
    
    //remfirst(head,tail);
    //remlast(head,tail);
    //displayreverserecursive(head);
    //int sz=size(head);
    node*left=head;
    node*right=head;
    node*fi=head;
    //revprec(left,right,sz);
    int sz=0;
    int f=0;
    //revprec2(left,right,f,sz);
    //display(head);

    bool n=ispalindrome(left,right,sz);
    //bool n=ispalindrome2(left,right);
   
    bool myn=checkpalindrome(head);
    cout<<n<<" "<<myn<<endl;
    display(head);

    //fold(left,right,f,sz,tail);
    //addfirst(head,tail,1);
    //addfirst(head,tail,1);
    //display(head);
    //unfold(fi,NULL,tail);
    //addlast(head,tail,17);
   // display(head);
    //int k=3;
    //addlast(head,tail,12);
    //krev2(head,tail,3);
    //addlast(head,tail,50);
    
    //display(head);

    //kfromlast(left,right,0,k);
    //int m=midrec(left,right);
    //int m=mid(head);
    //cout<<m<<endl;
    //oddeven(head,tail);
    //duplicacy(head,tail);
   // tail->next=getnode(head,3);
    //floyd(head);

    // node*h1=NULL;
    // node*t1=NULL;

    // addlast(h1,t1,20);
    // addlast(h1,t1,40);
    // addlast(h1,t1,60);
    // addlast(h1,t1,80);

    // display(h1);

    // node*h2=NULL;
    // node*t2=NULL;

    // mergesl(head,h1,h2,t2);

    node*sh=head;
    node*st=tail;

    //inplacemergesort(sh,st);
   // display(head);
    //display(sh);


    //display(h2);

}
