#include<iostream>
using namespace std;
class Array
{
   private:
    int *A;
    int size;
    int length;
   public:
    Array(){}
    ~Array()
    {
      delete []A;
    }
    // SET SIZE OF ARRAY
    void setSize();
    
    // SET LENGTH OF ARRAY
    void setLength();
    
    // ENTER ALL ELEMENT
    void Element();
    
    // DISPLAYING ARRAY
    void display();
    
    // INSERTING ELEMENT IN ARRAY
    void insertAtEnd();
    void insertAtIndex();
    
    //  DELETING ELEMENT OF ARRAY
    void deleteFromEnd();
    void deleteFromIndex();
    
    // LINEAR AND BINARY SEARCHING
    void linearSearch();
    void iterativeBinarySearch();
    int RBS(int key,int l ,int h);
    
    // GET  AND SET  FUNCTION
    void getElement();
    void setElement();
    
    // MAX OR MIN ELEMENT OF ARRAY
    void maxElement();
    void minElement();
    
    // SUM AND AVG OF ARRAY
    int sumOfElementOfArray();
    void averageOfArray();
    
    //   REVERSING OF ARRAY
    void reverseArray1();
    void reverseArray2();
    
    // SHIFTING OF ARRAY
    void leftShift();
    void rightShift();
    
    // ROTATION OF ELEMENT
    void leftRotation();
    void rightRotation();
    
    // MERGING ARRAY
    
    // MISSING ELEMENT
       void missingElement();
       void multipleMissing();
       void multipleMissingHashMethod();
    
    // REPEATING ELEMENT
       void repeatingElement();
       void repeatAndCount();
       void HashRepeatElement();
    
    // PAIR TO SUM
       
};

void Array::setSize()
{
    cout<<"Enter size of Array:";
    cin>>size;
    
    A = new int[size];
    
}

void Array::setLength()
{
    cout<<"Enter length of Array:";
    cin>>length;
    
}

void Array::Element()
{
    if(length==0){}
    else
    {
    cout<<"Enter element of Array:";
    for(int i=0 ; i<length ; i++)
    {
       cin>>A[i];
    }
    }
}

void Array::display()
{
    cout<<"Displaying Array:\n";
    for(int i=0 ; i<length ; i++)
    {
       cout<<A[i]<<" ";
    }
}

void Array::insertAtEnd()
{
    int x;
    cout<<"Enter element to insert at end:";
    cin>>x;
    
    if( length < size)
    {
      cout<<"Inserted"<<endl;
      A[length]=x;
      length++;
      display();
    }
    else 
      cout<<"Array is full";
}
void Array::insertAtIndex()
{
    int x;
    int index;
    cout<<"Enter Index and Element to insert:";
    cin>>index>>x;
    
    if(length < size)
    {
        if(index >=0 && index<=length)
        {
            cout<<"Inserted"<<endl;
            // Right shifting
            for(int i=length ; i> index ; i--)
            {
              A[i] = A[i-1];
            }
            A[index]=x;
            length++;
            display();
        }
        else
          cout<<"Invalid index";
    
    }
    else
      cout<<"Array is full";
    
}

void Array::deleteFromEnd()
{
    int x = A[length-1];
    cout<<endl;
    cout<<x<<" is deleted from end"<<endl;
    length--;
    display();
}

void Array::deleteFromIndex()
{
    int index ,x;
    cout<<"Enter index to delete:";
    cin>>index;
    if(index>=0 && index < length)
    {
       x= A[index];
       cout<<x<<" is deleted from index: "<<index<<endl;
        // Left shifting
       for(int i=index ; i<length-1 ;i++)
        {
          A[i]=A[i+1];
        }
        length--;
        display();
    }
    else
      cout<<"Invalid index";
}

void Array::linearSearch()
{
    int key;
    bool flag=true;
    cout<<"Enter key to search :";
    cin>>key;
    
    for(int i=0 ; i<length ;i++)
    {
        if(A[i]==key)
        {
          cout<<key<<" found at index: "<<i<<endl;
            flag=false;
        }
        
         
    }
    if(flag)
      cout<<"Not found";
}

void Array::iterativeBinarySearch()
{
    int l=0;
    int h=length-1;
    int key ,mid;
    bool flag =true;
    cout<<"Enter element to search :";
    cin>>key;
    
    while(l<=h)
    {
        mid=(l+h)/2;
        
        if(A[mid]==key)
        {
          cout<<"Found at index: "<<mid;
          cout<<endl;
          flag=false;
          break;
          
        }
        else if(A[mid] > key)
        {
          h=mid-1;
        }
        else
        {
           l=mid+1;
        }
        
    }
    if(flag)
      cout<<"Not found";
}

int Array::RBS(int key,int l ,int h)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        
        if(A[mid]==key)
           return mid;
        else if(A[mid]>key)
           return RBS(key,l,mid-1);
        else
           return RBS(key,mid+1,h);
    
    }
    return -1;
    
}

void Array::getElement()
{
    int index;
    cout<<"Enter index to get element:";
    cin>>index;
    
    if(index>=0 && index <length)
    {
      cout<<A[index];
    }
    else
      cout<<"Invalid index";
}

void Array::setElement()
{
    int index,x;
    cout<<"Enter element and index to set:";
    cin>>x>>index;
    if(index>=0 && index<length)
    {
       cout<<"Element setted"<<endl;
       A[index]=x;
       display();
    }
    else
     cout<<"Invalid index";
}

void Array::maxElement()
{
    int max;
    max=A[0];
    
    for(int i=1 ; i<length ; i++)
    {
       if(A[i]>max)
        {
           max=A[i];
        }
    }
    cout<<"Max element : "<<max;
}

void Array::minElement()
{
    int min=A[0];
   
    for(int i=1 ; i<length ;i++)
    {
       if(A[i]<min)
         min= A[i];
    }   
    cout<<"Min element : "<<min;
}

int Array::sumOfElementOfArray()
{
    int sum=0;
    for(int i=0 ; i<length ; i++)
    {
        sum=sum + A[i];
    }
    return sum;
}

void Array::averageOfArray()
{
    int avg;
    avg= sumOfElementOfArray()/length;
    cout<<"Average of Array : "<<avg;
}

/*
void swap(int *a1 , int *a2)
{
    int temp= *a1;
    *a1= *a2;
    *a2 =temp;
}
*/

void Array::reverseArray1()
{
    int i ,j;
    
    for(i=0 ,j=length-1 ; i<j;i++,j--)
    {
       //swap(A[i],A[j]);
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        
    }
    display();
}

void Array::reverseArray2()
{
    int *B= new int[length];
    
    int i,j;
   for(i=length-1 ,j=0 ; i>=0 ; i-- , j++)
    {
       B[j]=A[i];
    }
   /* displaying temp array
    
   for(i=0 ; i<length ;i++)
   {
     cout<<B[i]<<" ";
   }
   */
    
    // initialise B to A
    for(i=0 ; i<length ; i++)
    {
        A[i]=B[i];
    }
    display();
}
int main()
{
    Array A;
    A.setSize();
    A.setLength();
    
    // set initial element of Array
    A.Element();
    
    //A.insertAtEnd();
    //A.insertAtIndex();
    //A.deleteFromEnd();
    //A.deleteFromIndex();
    //A.linearSearch();
    //A.iterativeBinarySearch();
    
    // Recursive Binary  search
    
    /*
    int key;
    int lower;
    int upper;
    cout<<"Enter key to search:";
    cin>>key;
    
    cout<<"Enter lower & upper index:";
    cin>>lower>>upper;
    
    int x =A.RBS(key,lower,upper);
    if(x!= -1)
      cout<<"Found At index :"<<x;
    else
      cout<<"Not found";
    */
    
    //A.getElement();
    //A.setElement();
    
    //A.maxElement();
    //A.minElement();
    
    // cout<<A.sumOfElementOfArray();
    //A.averageOfArray();
    
    //A.reverseArray1();
    //A.reverseArray2();
    
    //A.display();
    return 0;

}
