#include<iostream>
using namespace std;
class Stack
{
   private:
    int size;
    int top;
    int *S; 
   public:
    Stack(){top=-1;}
    void create();
    void display();
    void push();
    int pop();
    int isEmpty();
    int isFull();
    int stackTop();
    int peek();
   
    
    
};
void Stack::create()
{
    cout<<"Enter size :";
    cin>>size;
    S=new int[size];
}
void Stack::display()
{
    int i;
    for(i=top ; i>=0 ;i--)
      cout<<S[i]<<" ";
    cout<<endl;
}
void Stack::push()
{
    int x;
    cout<<"Enter to push:";
    cin>>x;
    if(top==size-1)
     cout<<"Overflow"<<endl;
    else
     S[++top]=x; 
}
int Stack::pop()
{
    int x=-1;
    if(top==-1)
      cout<<"Underflow"<<endl;
    else
      x=S[top--];
    return x;
}
int Stack::isEmpty()
{
    if(top==-1)
       return 1;
    return 0;
}
int Stack::isFull()
{
    if(top==size-1)
       return 1;
    return 0;
}
int Stack::stackTop()
{
    if(!(isEmpty()))
      return S[top];
    return -1;
}
int Stack::peek()
{
    int pos;
    cout<<"Enter position:";
    cin>>pos;
    int x=-1;
    if(top-pos+1<0)
       cout<<"Invalid position"<<endl;
    else
       x=S[top-pos+1];
    return x;
}
int main()
{
    Stack s1;
    s1.create();
    
    s1.push();
    s1.push();
    cout<<s1.peek();
    
    
    
    
    
    
    
    
    return 0;
}