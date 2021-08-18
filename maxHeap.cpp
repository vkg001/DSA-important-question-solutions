#include<iostream>

#define loop(a,b)   for(int i=a;i>=b;i--)

using namespace std;




void heap(int* arr, int n)
{
    int i,k;
    loop(n-1,0)
    {
        k=i/2;
        if(arr[i]>arr[k])
        {
            int t;
            t=arr[i];
            arr[i]=arr[k];
            arr[k]=t;
        }
    }
}


int main()
{
    int arr[]={4,5,3,2,6,1};
    heap(arr,6);
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    return 0;
}
