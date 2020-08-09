#include<iostream>
using namespace std;
class Node
{
    public:
     Node *lChild;
     int data;
     Node *rChild;
    
};
class Queue
{
  private:
    int size;
    int front;
    int rear;
    Node** Q;
  public:
    Queue(int x)
     {
        front=rear=-1;
        size=x;
        Q=new Node*[size];
     
     }
    ~Queue(){delete []Q;}
    void enqueue(Node *x);
    Node* dequeue();
    int isEmpty();
    int isFull();
    //void display();
  
};
void Queue::enqueue(Node *x)
{
    if(rear==size-1)
    {
      cout<<"Queue is Full\n";
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node *x=NULL;
    if(rear==front)
      cout<<"Queue is Empty\n";
    else
       x=Q[++front];
    return x;
}
int Queue::isEmpty()
{
    return rear==front;
}
int Queue::isFull()
{
    return rear==size-1;
}
/*void Queue::display()
{
    int i;
    cout<<"Displaying Queue\n";
    for(i=front+1 ;i<=rear ;i++)
      cout<<Q[i]<<" ";
    cout<<endl;
} */



class Tree
{
   private:
    Node *root;
    
   public:
    Tree(){root=NULL;}
    ~Tree(){delete root ;}
    void createTree();
    void Preorder();
    void Preorder(Node *t);
    void Inorder();
    void Inorder(Node *t);
    void Postorder();
    void Postorder(Node *t);
     
    
    
};
void Tree::createTree()
{
    Node *p ;
    Node *t=NULL;
    int n;
    cout<<"Enter No. of Node:";
    cin>>n;
    Queue q(n);
    int x;
    cout<<"Enter root value :";
    cin>>x;
    root =new Node;
    root->data=x;
    root->lChild=NULL;
    root->rChild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter "<<p->data;
        cout<<" Left child :";
        cin>>x;
        
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lChild=NULL;
            t->rChild=NULL;
            p->lChild=t;
            q.enqueue(t);
        
        }
        
        cout<<"Enter "<<p->data;
        cout<<" right child :";
        cin>>x;
        
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lChild=NULL;
            t->rChild=NULL;
            p->rChild=t;
            q.enqueue(t);
        
        }
    
    }
    
}

void Tree::Preorder()
{   
    cout<<"Preorder Traversal \n";
    Preorder(root); 
}
void Tree::Preorder(Node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        Preorder(t->lChild);
        Preorder(t->rChild);

    }
    
}

void Tree::Inorder()
{
    cout<<"\nInorder Traversal \n";
    Inorder(root);

}

void Tree::Inorder(Node *t)
{
    if(t!=NULL)
    {
        Preorder(t->lChild);
        cout<<t->data<<" ";
        Preorder(t->rChild);

    }
}

void Tree::Postorder()
{
    cout<<"\nPostorder Traversal \n";
    Postorder(root);
}

void Tree::Postorder(Node *t)
{
    if(t!=NULL)
    {
        Postorder(t->lChild);
        Postorder(t->rChild);
        cout<<t->data<<" ";
    
    }
}
int main()
{
        
       
   /* Queue q(2);
    q.enqueue(4);
    //q.enqueue(2);
    cout<<q.isFull()<<endl;
    q.display();
    q.dequeue();
    //q.dequeue();
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.display(); */
    
    Tree t;
    t.createTree();
    t.Preorder();
    t.Inorder();
    t.Postorder();
     
    
    return 0;
}