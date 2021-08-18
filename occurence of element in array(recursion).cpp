#include<iostream>
using namespace std;

int firstindex(int* brr, int size, int k, int index)
{
    if(brr[index]==k)   return index;
    if(index==size)   return -1;
    return (firstindex(brr,size,k,index+1));
}

int lastindex(int* brr, int size, int k)
{
    if(brr[size]==k)   return size;
    if(size<0)   return -1;
    return (lastindex(brr,size-1,k));
}

int main()
{
    int n,i,k;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    cout<<"Enter element to check first & last occurence : ";
    cin>>k;
    i=firstindex(brr,n-1,k,0);
    if(i==-1)   cout<<"Element not present in array";
    else
    {
        cout<<"First occurence of "<<k<<" is at position."<<i+1;
        i=lastindex(brr,n-1,k);
        cout<<"\nLast occurence of "<<k<<" is at position."<<i+1;
    }
    return 0;
}
