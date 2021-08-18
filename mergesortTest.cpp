#include<iostream>
using namespace std;

void Merge(int *arr, int lb, int mid, int ub)
{
    int res[ub-lb+1],start,end,k=0;
    start=lb;  end=mid+1;
    while(start<=mid  &&  end<=ub)
    {
        if(arr[start]<arr[end])
        {
            res[k]=arr[start];
            start++;
        }
        else
        {
            res[k]=arr[end];
            end++;
        }
        k++;
    }
    cout<<"Loop 1 clear"<<endl;
    while(start<=mid)
    {

        res[k]=arr[start];
        start++;
        k++;
    }
    cout<<"Loop 2 clear"<<endl;
    cout<<end<<" | "<<ub<<endl;
    while(end<=ub);
    {
        cout<<"Stuck 3"<<endl;
        res[k]=arr[end];
        end++;
        k++;
    }
    cout<<"Loop 3 clear"<<endl;
    for(int i=0;i<k;i++)
    {
        arr[lb+i]=res[i];
    }
}


void mergesort(int *arr, int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    }
}



int main()
{
    int *arr,n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter elements\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    mergesort(arr,0,n-1);
    cout<<"Sorted array\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    return 0;

}