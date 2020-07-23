#include<iostream>
using namespace std;
class Node
{
    private:
      int data;
      Node * next;
    public:
    
      //CREATING LINKEDLIST From Array
      void createLinkedList(int *A,int n);
      
      /* Taking element from Array
         and making linked list */
      void enterElement();
    
      /* DISPLAY LINKED LIST
        1.Iterative approach
        2.Recursive approach  */
      
      void display();
      void displayRecursive(Node *temp);
    
      //INSERTING AT PARTICULAR POSITION
      void insertAtPosition();
    
      /* COUNTING NODE
        1.ITERATIVE
        2. RECURSIVE  */
      void countingNodeIterative();
    int countingNodeRecursive(Node *t);
    
    /* SUM OF ALL ELEMENT
      1.Iterative
      2.Recursive  */
    void sumOfElementIterative();
    int sumOfElementRecursive(Node *t);
    
    /* MAXIMUM AND MINIMUM
      1.Iterative
      2.Recursive  */
    void maximumIterative();
    void minimumIterative();
    
    int maximumRecursive(Node *t);
    int minimumRecursive(Node *t);
    
    // Linear search
    
    void linearSearch();
    
    /*Improve linear search
      1. Move to head */
    
    /* INSERTING NODE IN LINKED LIST
      1. All at begining
      2. All at last
      3. Between two nodes or anywhere
    */
      
     void insertAtBegining();
     void insertAtLast();
     void insertAtAnyPosition();
    
     // Insert in sorted linked list
     void insertInSortedLinkedList();
    
   // Delete node/element from linked list
     int deleteElement();
    
  // check list is sorted or not;
    void checkSort();
    
   // Remove duplicate element
    void  removeDuplicate();
    
   // Reverse linked list

   // Concatination & Merge two list


};
Node *head;
void Node::enterElement()
{
    int n;
    cout<<"Enter No of element:";
    cin>>n;
    
    
   int *A =new int[n];
    int i=0;
    while(i<n)
    {
        cin>>A[i];
        i++;
    }
    createLinkedList(A,n);
}
void Node::createLinkedList(int *A,int n)
{
    Node *last;
    Node *temp1;
    head=new Node;
    head->data=A[0];
    head->next=NULL;
    last=head;
    int i;
    for( i=1; i<n; i++)
    {
        temp1=new Node;
        temp1->data=A[i];
        temp1->next=NULL;
        last->next=temp1;
        last=temp1;
    
    }

      
}
void Node::display()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    
    }
}

void Node::displayRecursive(Node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        displayRecursive(temp->next);
    }
}

void Node::insertAtPosition()
{
    int pos ,n;
    
    cout<<"Enter position and no :";
    cin>>pos>>n;
    
    Node *temp1 =new Node;
    temp1->data=n;
    if(pos==1)
    {
        temp1->next=head;
        head=temp1;
        return ;
    
    }
    Node *temp2=head;
    int i;
    for(i=0;i<pos-2;i++)
    {
         temp2=temp2->next;
    }
    temp1->next =temp2->next;
    temp2->next =temp1;
    
}

void Node::countingNodeIterative()
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    
    }
    cout<<"No of nodes :"<<count;
    
}

int Node::countingNodeRecursive(Node *t)
{
    if(t==NULL)
       return 0;
    else
    {
  return countingNodeRecursive(t->next)+1;
    }
}

void Node::sumOfElementIterative()
{
    Node *temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->next;
    
    }
    cout<<"Sum ="<<sum;
}

int Node::sumOfElementRecursive(Node *t)
{
    if(t==NULL)
       return 0;
    else
    {
      return sumOfElementRecursive(t->next)+t->data;
    }
}

void Node::maximumIterative()
{
    Node *temp=head;
    int max=-32768;
    while(temp!=NULL)
    {
        if(temp->data > max)
            max=temp->data;
        temp=temp->next;
    
    }
    cout<<max;
}

void Node::minimumIterative()
{
    int min=32768;
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data<min)
           min=temp->data;
        temp=temp->next;
    
    }
    cout<<"Min ="<<min;
}

int Node::maximumRecursive(Node *t)
{
    int x=0;
    if(t==NULL)
    {
        return -32768;
   
    }
    x=maximumRecursive(t->next);
    if(x>t->data)
       return x;
    else
       return t->data;
}

int Node::minimumRecursive(Node *t)
{
    int x;
    if(t==NULL)
      return 32768;
    x=minimumRecursive(t->next);
    /*if(x<t->data)
       return x;
    else
       return p->data;*/
    return x < t->data ? x : t->data;
}
  
void Node::linearSearch()
{
    int key;
    int count=0;
    bool flag=true;
    cout<<"Enter a no. to search:";
    cin>>key;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        if(key==temp->data)
        {
       cout<<"Found at position :"<<count;
            flag=false;
            break;
        }
        temp=temp->next;

    }
    if(flag)
      cout<<"Not found";
    
}

void Node::insertAtBegining()
{
    int n;
    cout<<"Enter elment to insert at begining :";
    cin>>n;
    Node *temp =new Node;
    temp->data=n;
    temp->next=head;
    head=temp;
    display();
    
}

void Node::insertAtLast()
{
    int n;
  cout<<"Enter  element to insert at end";
    cin>>n;
    Node *temp=head;
    Node *last=NULL;
    while(temp!=NULL)
    {
        last=temp;
        temp=temp->next;
    
    }
    Node *temp1 = new Node;
    temp1->data=n;
    temp1->next=NULL;
    last->next=temp1;
    
    display();
    
}
void Node::insertAtAnyPosition()
{
    int pos,n;
    cout<<"Enter position and number to insert :";
    cin>>pos>>n;
    if(pos>=0 && pos<=countingNodeRecursive(head) )
  {
    Node *temp=new Node;
    temp->data=n;
    if(pos==0)
    {
       temp->next=head;
       head=temp;
       return ;
    }
    Node *temp1=head;
    for(int i=0 ; i<pos-1 ;i++)
    {
       temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
  }
  else
     cout<<"Invalid position"<<endl;
    
    
}

void Node::insertInSortedLinkedList()
{
    int key;
    cout<<"Enter key :";
    cin>>key;
    Node *t=new Node;
    t->data=key;
    t->next=NULL;
    if(head==NULL)
       head=t;
    else
    {
        Node *p=head; // Iterative pointer
        Node *q=NULL; // Following pointer
        while(p!=NULL && p->data <key)
        {
            q=p;
            p=p->next;
        
        }
        if(p==head)
        {
            t->next=head;
            head=t;
        
        }
        else
        {
        t->next =q->next;
        q->next =t;
        }
        
    
    }
    display();
}


int Node::deleteElement()
{
    int pos,i,x;
    cout<<"Enter element no:";
    cin>>pos;
    if(pos>=1 && pos<=countingNodeRecursive(head))
    {
        if(pos==1)
        {
            Node *p=head;
            head=p->next;
            x=p->data;
            delete p;
            return x;
        
        } 
        else
        {
            Node *p=head;
            Node *q=NULL; // Following ptr
            for(i=0;i<pos-1;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            x=p->data;
            delete p;
            return x;
            
            
    
        }
    
    }
    else
    {
          cout<<"Invalid index";
          return -1;
      
    }
}

void Node::checkSort()
{
    int x=-32768;
    Node *p=head;
    while(p!=NULL && p->data >x )
    {
        x=p->data;
        p=p->next;
    }
    if(p==NULL)
    {
       cout<<"Sorted";
    }
    else
       cout<<"Unsorted";
}

void Node::removeDuplicate()
{
    Node *p=head;
    Node *q=head->next;
    
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
            

        }
    
    }
    display();
}
int main()
{
    head=NULL;
    
    Node list1;
    
   
    list1.enterElement();
    
    //list1.insertAtPosition();
    
    //list1.display();
    //list1.displayRecursive(head);
    
   //list1.countingNodeIterative();
//cout<<list1.countingNodeRecursive(head);
    
    //list1.sumOfElementIterative();
//cout<<list1.sumOfElementRecursive(head);
    
    //list1.maximumIterative();
    //list1.minimumIterative();
    
    //cout<<list1.maximumRecursive(head);
    //cout<<list1.minimumRecursive(head);
    
   //list1.linearSearch();
    
    //list1.insertAtBegining();
   // list1.insertAtLast();
    
    //list1.insertAtAnyPosition();
    
    /* CREATING LINKED LIST BY INSERTING
    
      // first index must be 0
    
    int noOfNodes;
    cout<<"\nEnter No of node you want :";
    cin>>noOfNodes;
    
    for(int i=1 ;i<=noOfNodes ;i++)
    {
    list1.insertAtAnyPosition();
        list1.display();
        cout<<endl;
    }
    */
    
    /* CREATING LINKED BY INSERTING ALL TO LAST */
    
    //list1.insertInSortedLinkedList();
    
    /*cout<<list1.deleteElement();
    cout<<endl;
    list1.display(); */
    
    //list1.checkSort();
    
    list1.removeDuplicate();
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}