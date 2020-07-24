#include<iostream>
using namespace std;
class Node
{
    public:
 
    int data;
    Node *next;
    
};
class CLL
{
    Node *head;
    public:
      CLL(){head=NULL;}
     ~CLL(){delete head;}
      void create(int A[] ,int n);
      void display();
      int length();
      void insert();
      int deleteNode();
};
void CLL::create(int A[],int n)
{
    Node *t;
    Node *last;
    int i;
    head=new Node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1 ; i<n ; i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    
    }
}
void CLL::display()
{
    Node *p=head;
    do
   {
     cout<<p->data<<" ";
     p=p->next;
    
   }while(p!=head);
}
int CLL::length()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
    Node *p=head;
    int l=1;
    while(p->next!=head)
    {
        l++;
        p=p->next;
    
    }
    return l;
   }
    
}

void CLL::insert()
{
    int pos,x;
    cout<<"\nEnter pos & No:";
    cin>>pos>>x;
    if(pos>=0 && pos<=length())
    {
        if(pos==0)
        {
        Node *t;
        t=new Node;
        t->data=x;
        if(head==NULL)
         {
            head=t;
            head->next=head;
         }
         Node *p=head;
         while(p->next!=head)
          {
            p=p->next;
          }
           p->next=t;
           t->next=head;
           head=t;
        
        }
        else
        {
            Node *t;
            t=new Node;
            t->data=x;
            int i;
            Node *p=head;
            for(i=0; i<pos-1 ;i++)
            {
               p=p->next;
            }
            t->next=p->next;
            p->next=t;
      
        }
        
    
    }
    else
      cout<<"Invalid Position";
}

int CLL::deleteNode()
{
    int pos;
    int x;
    cout<<"Enter position to delete:";
    cin>>pos;
    if(pos>=1 && pos<=length())
    {
        if(pos==1)
        {
           Node *p=head;
           x=head->data;
           while(p->next!=head)
           {
             p=p->next;
           }
            
           if(p==head)
            {
              delete head;
              head=NULL;
            }
           p->next=head->next;
            delete head;
           head=p->next;
            return x;
        }
        else
        {
            Node *p=head;
            int i;
            for(i=0 ; i<pos-2 ;i++)
            {
              p=p->next;
            }
            Node *q=p->next;
            x=q->data;
            p->next=q->next;
            delete q;
            
            return x;
    
        }
        
    
    }
    else
      return -1;
}

int main()
{
    int A[]={1,2,3,4,5};
    CLL list1;
    list1.create(A,5);
    list1.display();
    cout<<list1.deleteNode()<<endl;
    list1.display();
    //list1.insert();
    
    
    //cout<<"Length :"<<list1.length()<<endl;
    
    return 0;

}