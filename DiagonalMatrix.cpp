#include<iostream>
using namespace std;
class DiagonalMatrix
{
  private:

    int size;
    int *A;
    
  public:
    DiagonalMatrix()
        {size=4;A=new int[size];}
    DiagonalMatrix(int size)
    {
        this->size=size;
        A=new int[size];
    }
    void set(int i ,int j ,int x);
    int  get(int i ,int j);
    void display();
    
};

void DiagonalMatrix::set(int i ,int j ,int x)
{
    if(i==j)
       A[i-1]=x;
}

int  DiagonalMatrix::get(int i ,int j)
{
    if(i==j)
       return A[i-1];
    else return 0;
}

void DiagonalMatrix::display()
{
    int i,j;
    for(i=0 ;i<size ;i++)
    {
        for(j=0 ; j<size ;j++)
        {
            if(i==j)
              cout<<A[i]<<" ";
            else
              cout<<"0 ";
        
        }
        cout<<endl;

    }
}
int main()
{
    DiagonalMatrix m(5);
    m.set(1,1,2);
    m.set(2,2,3);
    m.set(3,3,4);
    m.set(4,4,5);
    m.set(5,5,6);
    
    cout<<m.get(5,3)<<endl;
    
    m.display();
    
    
    
    
}