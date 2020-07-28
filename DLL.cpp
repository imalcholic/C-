#include<iostream>
using namespace std;
class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
    
};
class DLL
{
    Node *head;
   public:
     DLL(){head=NULL;}
     ~DLL(){delete head;}
     void create(int A[] ,int n);
     void display();
     int length();
     void insert();
     int removeNode();
     void reverseElement();

};
void DLL::create(int A[] ,int n)
{
    Node *t ,*last;
    int i;
    
    head=new Node;
    head->prev=NULL;
    head->data=A[0];
    head->next=NULL;
    last=head;
    
    for(i=1 ;i<n ;i++)
    {
        t=new Node;
        t->prev=last;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    

    }
    
}
void DLL::display()
{
    Node *p=head;
    while(p!=NULL)
    {
       cout<<p->data<<" ";
        p=p->next;
    }
}
int DLL::length()
{
    Node *p=head;
    int len=0;
    while(p!=NULL)
    {
       len++;
       p=p->next;
    }
    return len;
}
void DLL::insert()
{
    int pos,x;
    Node *t;
    int i;
    cout<<"\nPosition & Number :";
    cin>>pos>>x;
    if(pos>=0 && pos<=length())
    {
        if(pos==0)
        {
            t=new Node;
            t->prev=NULL;
            t->data=x;
            if(head==NULL)
            {
               head=t;
               head->next=NULL;
            }
            else
            {
            t->next=head;
            head->prev=t;
            head=t;
                
            }
        
        }
        else
        {
            t=new Node;
            t->data=x;
            
            Node *p=head;
            for(i=0 ;i<pos-1 ;i++)
               p=p->next;
            
            t->prev=p;
            t->next=p->next;
            if(p->next!=NULL)
               t->next->prev=t;
            p->next=t;
            
    
        }
      
    }
    else
     cout<<"Invalid Position";
}
int DLL::removeNode()
{
    Node *p;
    int pos;
    int x;
    int i;
    cout<<"Enter position:";
    cin>>pos;
    if(pos>=1 && pos<=length())
    {
        if(pos==1)
        {
            if(head==NULL)
               return -1;
            p=head;
            x=head->data;
            head=head->next;
            delete p;
            if(head!=NULL)
              head->prev=NULL;
            return x;
    
        }
        else
        {
            p=head;
            for(i=0;i<pos-1;i++)
               p=p->next;
            p->prev->next=p->next;
            x=p->data;
            if(p->next!=NULL)
               p->next->prev=p->prev;
            delete p;
            return x;
            
    
        }

        
    }
    else
      return -1;
    

}
void DLL::reverseElement()
{
    Node *p=head;
    Node *temp;
    
    while(p!=NULL)
    {
       // swaping next and prev
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        
        p=p->prev;
        
        if(p!=NULL && p->next==NULL)
           head=p;
    
    }
    

    
}
int main()
{
    DLL list1;
    
    int A[]={1,2,3,4,5};
    
    
    list1.create(A,5);
    list1.display();
    cout<<endl;
    /*
    
    cout<<endl;
    
    cout<<"Length :"<<list1.length();
    
    list1.insert();
    
    cout<<endl;
    list1.display();
    cout<<endl;
    cout<<"Length :"<<list1.length();
    
    cout<<list1.removeNode();
    cout<<endl;
    list1.display();*/
    
    list1.reverseElement();
    list1.display();
    return 0;
}