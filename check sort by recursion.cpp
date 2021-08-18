#include<iostream>
using namespace std;

bool chksort(int* brr, int size, int index)
{
    if(index==size)   return true;
    if(brr[index]<brr[index-1])   return false;
    else   return (chksort(brr,size,index+1));
}

int main()
{
    int n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    i=chksort(brr,n-1,1);
    if(i==0)  cout<<"Given array is not sorted in ascending order.";
    else   cout<<"Given array is sorted in ascending order.";
    return 0;
}
