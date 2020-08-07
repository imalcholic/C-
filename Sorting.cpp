#include<iostream>
using namespace std;
class Array
{
    int size;
    int length;
    int *A;
    
    public:
      Array(){}
      void enterSize();
      void enterLength();
      void enterElement();
      void display();
      int findMax();
    
      // Bubble sort
      void BubbleSort();
      
      // Insertion sort
      void InsertionSort();
    
      // Selection Sort
      void SelectionSort();

      // Count Sort Index based
      void CountSort();
};
void Array::enterSize()
{
    cout<<"Enter size:";
    cin>>size;
}
void Array::enterLength()
{
    
    cout<<"Enter length:";
    cin>>length;
    while(length>size)
    {
        cout<<"Invalid Length"<<endl;
        cout<<"Enter Again:";
        cin>>length;
    }
    A=new int[length];
}
void Array::enterElement()
{
    cout<<"Enter element:";
    for(int i=0 ;i<length ; i++)
       cin>>A[i];
}
void  Array::display()
{
    cout<<"Displaying array \n";
    for(int i=0 ;i<length ;i++)
       cout<<A[i]<<" ";
    cout<<endl;
}

//sorting in Ascending order

void Array::BubbleSort()
{
    int i,j;
    bool flag;
    // Pass is 1 less than element
    for(i=0 ; i<length-1 ;i++)
    {
        flag=true;
      /*Comparison is 1 less after
         each  iteration */
        for(j=0 ;j<length-1-i ;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                
             // If swapping is happen then
                flag=false;
            
            }
        
        }
        /*If swapping is happend 
           then list is already sorted
          then break through loop
        */
        
        if(flag)
          break;
    
    }

}

//Insertion is designed for Linked List
//sorting in ascending order

void Array::InsertionSort()
{
    int i,j,x;
    for(i=1 ;i<length ;i++ )
    {
        x=A[i];
        j=i-1;
        //shifting Element
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        
        }
        A[j+1]=x;

    }
}

void swap(int *i ,int *k)
{
    int temp=*i;
    *i=*k;
    *k=temp;

}
void Array::SelectionSort()
{
    int i,j,k;
    for(i=0 ; i<length-1 ; i++)
    {
        for(j=k=i ; j<length ; j++)
        {
            if(A[j]<A[k])
               k=j;

        }
        swap(&A[i],&A[k]);

    }
}

int Array::findMax()
{
    int max=A[0];
    int i;
    for(i=1 ; i<length ; i++)
    {
        if(A[i]>max)
          max=A[i];
           
    }
    return max;
}

void Array::CountSort()
{
    int max=findMax();
    max=max+1;
    int *C=new int[max];
    
    int i,j;
    // Initialise all element to zero
    for(i=0 ; i<max ;i++)
       C[i]=0;
    
   // Traversing in Normal Array
    for(i=0 ;i<length ; i++)
       C[A[i]]++;
   
   // Traversing in Dynamic created Array
   // And copying in main array
    i=0;
    j=0; //Destination Array counter
    while(i<max)
    {
        if(C[i]>0)
        {
           A[j]=i;
           j++;
           C[i]--;
        }
        else
          i++;
    
    }
}
int main()
{
    Array a;
    a.enterSize();
    a.enterLength();
    a.enterElement();
    a.display();
    
    /* a.BubbleSort(); 
   
     a.InsertionSort();
    
    a.SelectionSort(); */
    
     a.CountSort();
     a.display();
    
     // cout<<"Max :"<<a.findMax();
    return 0;

}