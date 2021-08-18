#include<iostream>
#include<climits>
using namespace std;

void quicksort(int*,int,int);
int partition(int*,int,int);
int main()
{
    int n,i,left=0,right,sum,k,f=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    cout<<"Enter sum of pair: ";
    cin>>k;
    right=n-1;
    quicksort(brr,0,n-1);
    cout<<"Sorted array-> ";
    for(i=0;i<n;i++)   cout<<brr[i]<<"  ";
    sum=brr[left]+brr[right];
    while(left<right)
    {
        if(sum==k)
        {
            cout<<"\nPair found at position "<<left<<"&"<<right;
            f=1;
            break;
        }
        else if(sum<k)
        {
            left++;
            sum=brr[left]+brr[right];
        }
        else if(sum>k)
        {
            right--;
            sum=brr[left]+brr[right];
        }
    }
    if(f==0)   cout<<"Pair not found.";
    return 0;
}

void quicksort(int* brr, int lb, int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(brr, lb, ub);
        quicksort(brr, lb, loc-1);
        quicksort(brr, loc+1, ub);
    }
}


int partition(int* brr, int lb, int ub)
{
    int strt,end,pivot,i;
    strt=lb;
    pivot=brr[lb];
    end=ub;
    while(strt<end)
    {
        while(brr[strt]<=pivot)   strt++;
        while(brr[end]>pivot)    end--;
        if(strt<end)
        {
            i=brr[strt];
            brr[strt]=brr[end];
            brr[end]=i;
        }
    }
    i=brr[end];
    brr[end]=pivot;
    brr[lb]=i;
    return end;
}
