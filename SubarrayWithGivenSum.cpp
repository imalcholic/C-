#include<iostream>
using namespace std;
void print(int arr[] ,int i,int j)
{
    cout<<"["<<i<<"]"<<"..."<<"["<<j<<"] :  {";
    for(int k=i ; k<=j ;k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<"}"<<endl;
}
void subArray(int arr[] ,int n ,int sum)
{
    for(int i=0;i<n;i++)
    {
        
        int sum_so_far=0;
        for(int j=i ;j<n;j++ )
        {
           sum_so_far += arr[j];
        
           if(sum_so_far ==sum)
           {
              print(arr,i,j);
           }
        }
    
    }
}
int main()
{
    int arr[]={3,4,-7,1,3,3,1,-4};
    int sum=7;
    int n=sizeof(arr)/sizeof(arr[0]);
    subArray(arr,n,sum);
    return 0;
}