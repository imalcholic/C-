#include<iostream>
using namespace std;
void kadnae(int A[] ,int n)
{
    int localSum=A[0];
    int globalSum=A[0];
    int i;
    int start=0 ,end=0;
    int beg=0;
    
    for(i=1;i<n;i++)
    {
       localSum += A[i];
       if(localSum < A[i])
        {
           localSum=A[i];
            beg=i;
        }
       if(globalSum <localSum)
        {
           globalSum=localSum;
           start=beg;
           end=i;
        }
    }
    cout<<"Maximum sum : "<<globalSum;
    cout<<endl;
    int k;
    for(k=start ; k<=end ;k++)
    {
      cout<<A[k]<<" ";
    }
}
int main()
{
    int arr[]={2,-4,4,6,-12};
    int n=sizeof(arr)/sizeof(arr[0]);
    kadnae(arr,n);
    return 0;
}