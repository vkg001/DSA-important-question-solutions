#include<iostream>
using namespace std;

void mergesort(int*, int, int);
void Merge(int*, int, int, int);
void SearchSum(int*, int, int);

int main()
{
    int *brr,n,i,key;
    cout<<"Enter number of elements: ";
    cin>>n;
    brr=new int [n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    cout<<"Enter sum : ";
    cin>>key;
    mergesort(brr, 0, n-1);
    for(i=0;i<n;i++)
        cout<<brr[i]<<"  ";
    cout<<endl;
    SearchSum(brr, key, n);
    return 0;
}


void mergesort(int* brr, int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(brr, lb, mid);
        mergesort(brr, mid+1, ub);
        Merge(brr, lb, mid, ub);
    }
}




void Merge(int* brr, int lb, int mid, int ub)
{
    int temp[ub-lb],i,j,k=0;
    i=lb;
    j=mid+1;
    while(i<=mid  and  j<=ub)
    {
        if(brr[i]<brr[j])
        {
            temp[k]=brr[i];
            i++;
        }
        else
        {
            temp[k]=brr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=brr[i];
        i++;
        k++;
    }
    while(j<=ub)
    {
        temp[k]=brr[j];
        j++;
        k++;
    }
    for(i=0;i<k;i++)
    {
        brr[lb+i]=temp[i];
    }
}


void SearchSum(int* brr, int key, int n)
{
    int temp=0,f,g,h,i,j,k,temp2;
    temp=f;
    for(k=0;k<n;k++)
    {
        f=brr[k];
        temp2=key-f;
        i=k+1;
        g=brr[i];
        j=n-1;
        h=brr[j];
        temp=g+h;
    while(i<j)
    {
        if(temp<=temp2)
        {
            if(temp==temp2)
            {
                cout<<"Triplet available ("<<f<<","<<g<<","<<h<<")"<<endl;
                return;
            }
            else
            {
                i++;
                g=brr[i];
                temp=g+h;
            }
        }
        else
        {
            j--;
            h=brr[j];
            temp=g+h;
        }
    }
    }
    cout<<"No triplet available for the required key."<<endl;
}
