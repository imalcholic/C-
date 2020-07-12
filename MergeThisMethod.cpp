#include<iostream>
using namespace std;

class Array
{
   private:
    int *A;
    int size;
    int length;
   public:
    void setSize();
    void setLength();
    void setElement();
    void display();
    void merge(Array arr2);
};
void Array::setSize()
{
    cout<<"Enter size:";
    cin>>size;
    A =new int[size];
    
}
void Array::setLength()
{
    cout<<"Enter length:";
    cin>>length;

}
void Array::setElement()
{
    cout<<"Enter element:";
    for(int i=0 ;i<length ;i++)
    {
        cin>>A[i];

    }

}
void Array::display()
{
    cout<<"displaying Array:\n";
    for(int i=0 ;i<length;i++)
    {
       cout<<A[i]<<" ";
    }
}
void Array::merge(Array arr2)
{
    int newLength;
    newLength=this->length+arr2.length;
    int *C;
    C=new int[newLength];
    int i=0;
    int j=0;
    int k=0;
    
   
    while(i<this->length && j<arr2.length)
    {
        if(this->A[i] < arr2.A[j])
           C[k++]=this->A[i++];
        else
           C[k++]=arr2.A[j++];
    }
    for(;i<this->length;i++)
    {
        C[k++]=this->A[i];
     }
    for(;j<arr2.length ;j++)
    {
       C[k++]=arr2.A[j];
    }
    cout<<"Displaying merged array\n";
    for(i=0 ;i<newLength ;i++)
    {
      cout<<C[i]<<" ";
    }
}
int main()
{
    Array A;
    cout<<"Array 1st:\n";
    A.setSize();
    A.setLength();
    A.setElement();
   // A.display();
    
    cout<<"\nArray 2nd:\n";
    Array B;
    B.setSize();
    B.setLength();
    B.setElement();
    //B.display();
    
    A.merge(B);
    
    return 0;
}