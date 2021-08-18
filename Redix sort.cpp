#include<iostream>
using namespace std;


int retdigit(int n, int num)
{
    int div=1;
    for(int i=0;i<n;i++)
    {
        div*=10;
    }
    int x=num%div;
    div/=10;
    return x/div;
}

int countDigit(int n)
{
    int digit=0;
    while(n)
    {
        n/=10;
        digit++;
    }
    return digit;
}


void redixSort(int *arr, int n)
{
    int Queue[10][n],top[10];
    for(int i=0;i<10;i++)
        top[i]=-1;
    int digit=1,Max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(Max<arr[i])  Max=arr[i];
    }
    int MaxDigit=countDigit(Max);
    while(digit<=MaxDigit)
    {
        for(int i=0;i<n;i++)
        {
            //int test;
            int ret=retdigit(digit,arr[i]);
            //cout<<arr[i]<<" | "<<ret<<endl;
            //cin>>test;
            top[ret]++;
            Queue[ret][top[ret]]=arr[i];
            //cout<<top[ret]<<" | "<<ret<<endl;
        }
        int k=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<=top[i];j++)
            {
                arr[k++]=Queue[i][j];
            }
            top[i]=-1;
        }
        digit++;
    }
}


int main()
{
    int *arr,i,n;
    cout<<"Enter number of elements: ";
    cin>>n;
    arr= new int[n];
    cout<<"Enter elements\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    redixSort(arr,n);
    cout<<"Sorted array\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    return 0;
}
