#include<iostream>
using namespace std;
class Queue
{
  private:
    int size;
    int front;
    int rear;
    int *A;
    
  public:
    Queue(){}
    ~Queue(){delete []A;}
    void create();
    void display();
    void enqueue();
    int dequeue();
    int isEmpty();
    int isFull();
    int frontElement();
    int rearElement();
    
};

void Queue::create()
{
    cout<<"Enter size of queue:";
    cin>>size;
    A=new int[size];
    front=rear=-1;
}

void Queue::display()
{
    int i;
    cout<<"Displaying queue:\n";
    for(i=front+1 ;i<=rear ;i++)
    { 
      cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Queue::enqueue()
{
    int x;
    cout<<"Enter no. to enqueue :";
    cin>>x;
    if(rear==size-1)
      cout<<"Queue is full\n";
    else
      A[++rear]=x;
        
}

int Queue::dequeue()
{
    int x=-1;
    if(rear==front)
      cout<<"Queue is Empty\n";
    else
    {
       ++front;
       x=A[front];
    }
    return x;
}

int Queue::isEmpty()
{
    if(front==rear)
       return 1;
    return 0;
}

int Queue::isFull()
{
    if(rear==size-1)
       return 1;
    return 0;
}

int Queue::frontElement()
{
    int x=-1;
    if(front==rear)
      cout<<"Queue is Empty\n";
    else
    {
       x=A[++front];
    }
    return x;
}

int Queue::rearElement()
{
    int x=-1;
    if(front==rear)
      cout<<"Queue is Empty\n";
    else
       x=A[rear];
    return x;
}
int main()
{
    Queue q1;
    q1.create();
    //q1.enqueue();
    //q1.enqueue();
    //q1.display();
    cout<<q1.rearElement();
   
    
    return 0;
}