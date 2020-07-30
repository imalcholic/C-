#include<iostream>
using namespace std;
class CircularQ
{
  private:
    int size;
    int front;
    int rear;
    int *A;
    
  public:
    CircularQ(){}
    ~CircularQ(){delete []A;}
    void display();
    void create();
    void enqueue();
    int dequeue();
    int isFull();
    int isEmpty();

};

void CircularQ::display()
{
    int i=(front+1)%size;
    while(i!=((rear+1)%size))
    {
        cout<<A[i]<<" ";
        i=(i+1)%size;

    }
    cout<<endl;
    
}

void CircularQ::create()
{
    cout<<"Enter size:";
    cin>>size;
    A=new int[size];
    front=0;
    rear=0;
}

void CircularQ::enqueue()
{
    int x;
    cout<<"Enter no to enqueue:";
    cin>>x;
    if((rear+1)%size == front)
      cout<<"Queue is full\n";
    else
    {
       rear=(rear+1)%size;
       A[rear]=x;
    }
}
int CircularQ::dequeue()
{
    int x=-1;
    if(front==rear)
      cout<<"Queue is Empty\n";
    else
    {
        front=(front+1)%size;
        x=A[front];
    }
    return x;
}

int CircularQ::isFull()
{
    if((rear+1)%size==front)
       return 1;
    return 0;
}
int CircularQ::isEmpty()
{
    if(front==rear)
        return 1;
    return 0;
}
int main()
{
    CircularQ q1;
    
    q1.create();
    q1.enqueue();
    q1.enqueue();
   // q1.enqueue();
    cout<<q1.isFull()<<endl;
    
    
    /*cout<<q1.dequeue()<<endl;
    q1.display();
    
    cout<<q1.dequeue()<<endl;
    q1.display();
    
    cout<<q1.dequeue()<<endl;
    q1.display();
    
    cout<<q1.isEmpty()<<endl;*/
    q1.display();
    
    
    return 0;
}