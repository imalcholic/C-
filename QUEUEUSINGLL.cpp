#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;
    
  public:
    Queue(){front=rear=NULL;}
    ~Queue()
        {delete []front;
         delete []rear;
        }
    void enqueue();
    int dequeue();
    void display();
    int isEmpty();
    int frontElement();
    int rearElement();
};

void Queue::enqueue()
{
    int x;
    cout<<"Enter no to enqueue:";
    cin>>x;
    Node *t=new Node;
    if(t==NULL)
       cout<<"Queue is full"<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
           front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        
        }
    }
}

int Queue::dequeue()
{
    int x=-1;
    if(front==NULL)
      cout<<"Queue is Empty"<<endl;
    else
    {
        Node *p=front;
        front=front->next;
        x=p->data;
        delete p;
    
    }
    return x;
}

void Queue::display()
{
    Node *p=front;
    while(p!=NULL)
    {
       cout<<p->data<<" ";
       p=p->next;
    }
    cout<<endl;
}

int Queue::isEmpty()
{
    if(front==NULL)
       return 1;
    return 0;
}

int Queue::frontElement()
{
    if(front==NULL)
        return -1;
    return front->data;
}
int Queue::rearElement()
{
    if(rear==NULL)
       return -1;
    return rear->data;
}
int main()
{
    Queue q1;
    /*q1.enqueue();
    q1.enqueue();
    q1.enqueue();
    
    q1.display();
    
    q1.dequeue();
    /*q1.display();
    
    cout<<q1.dequeue()<<endl;
    q1.display();
    
    /*cout<<q1.dequeue()<<endl;
    q1.display();*/
    
   // cout<<q1.isEmpty();
    
    cout<<q1.frontElement()<<endl;
    cout<<q1.rearElement();
    return 0;
}