#include<iostream>
using namespace std;
int kadnae(int A[] ,int n)
{
    int localSum=A[0];
    int globalSum=A[0];
    int i;
    
    for(i=1;i<n;i++)
    {
       localSum += A[i];
       localSum=max(localSum ,A[i]);
       if(globalSum <localSum)
           globalSum=localSum;
    }
    return globalSum;
}
int main()
{
    int arr[]={2,-4,4,6,-12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<kadnae(arr,n);
    return 0;
}