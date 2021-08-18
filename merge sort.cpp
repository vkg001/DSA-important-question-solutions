#include<iostream>
using namespace std;
//int* sol;
void mergesort(int* brr, int lb, int ub);
void merge(int* brr, int lb, int mid, int ub);

int main()
{
    int* brr,n,i,j;
    cout<<"Enter number of elements: ";
    cin>>n;
    brr=new int [n];
    //sol= new int [n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    mergesort(brr,0,n-1);
    //cout<<"returned";
    //cin>>i;
    for(i=0;i<n;i++)
        cout<<brr[i]<<"  ";
    return 0;
}


void mergesort(int* brr, int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(brr,lb,mid);
        mergesort(brr,mid+1,ub);
        merge(brr,lb,mid,ub);
    }
    return;
}



void merge(int* brr, int lb, int mid, int ub)
{
    int i=lb,j=mid+1,k=0;
    int sol[ub-lb+1];
    while(i<=mid  &&  j<=ub)
    {
        if(brr[i]<brr[j])
        {
            sol[k]=brr[i];
            i++;
        }
        else
        {
            sol[k]=brr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        sol[k]=brr[i];
        i++;
        k++;
    }
    while(j<=ub)
    {
        sol[k]=brr[j];
        j++;
        k++;
    }
    for(i=0;i<=ub;i++)
        brr[lb+i]=sol[i];
}
