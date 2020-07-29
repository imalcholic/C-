#include<iostream>
using namespace std;
class Node
{
  public:
    int data;
    Node *next;
};

class Stack
{
   Node *top;
   public:
    Stack(){top=NULL;}
    ~Stack(){delete top;}
    void display();
    void push();
    int pop();
    int peek();
    int isEmpty();
    int isFull();
    int StackTop();

};
void Stack::display()
{
    Node *p=top;
    while(p!=NULL)
    {
      cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void Stack::push()
{
    int x;
    cout<<"Enter no to push:";
    cin>>x;
    Node *t=new Node;
    if(t==NULL)
      cout<<"Stack is Full"<<endl;
    else
    {
    t->data=x;
    t->next=top;
    top=t;
    }
    display();
    
}
int Stack::pop()
{
    int x=-1;
    if(top==NULL)  
    {
        cout<<" Stack is Empty"<<endl;
       return -1;
    }
    else
    {
        Node *p=top;
        top=top->next;
        x=p->data;
        delete p;
        return x;
        
    }


}
int Stack::peek()
{
    int pos;
    cout<<"Enter pos:";
    cin>>pos;
    Node *p=top;
    int i;
    for(i=0 ;p!=NULL && i<pos-1 ;i++)
       p=p->next;
    if(p!=NULL)
      return p->data;
    else
      return -1;
  
    
}
int Stack::isEmpty()
{
    if(top==NULL)
       return 1;
    else
       return -1;
}
int Stack::isFull()
{
    Node *t=new Node;
    if(t==NULL)
       return 1;
    delete t;
    return -1;
      
}
int Stack::StackTop()
{
    if(top==NULL)
       return -1;
    else
       return top->data;
}
int main()
{
    Stack s;
    s.push();
    s.push();
    cout<<s.isFull()<<endl;
    s.pop();
    s.pop();
    cout<<s.isFull();
    
   
    return 0;
}