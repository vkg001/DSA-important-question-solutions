#include<iostream>
using namespace std;

int Search(int x, int* arr, int n)
{
    int start, high, mid, i, low;
    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            high=i;
            start=i+1;
        }
    }
    if(x>=arr[0])
    {
        low=0;
        mid=(low+high)/2;
        while(low<high)
        {
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]<x)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
    }

    else
    {
        low=n-1;
        mid=(start+low)/2;
        while(start<low)
        {
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]<x)
                start=mid+1;
            else
                low=mid-1;
        }
    }
}



int main()
{
    int arr[]={30,40,50,10,20};
    cout<<Search(30,arr,5);
    return 0;
}
