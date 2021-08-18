#include<iostream>
using namespace std;
void wavesort(int* brr, int size);

int main()
{
    int* brr,n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    brr = new int [n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    wavesort(brr,n);
    for(i=0;i<n;i++)
        cout<<brr[i]<<"  ";
    return 0;
}

void wavesort(int* brr, int size)
{
    int i;
    for(i=1;i<size;i+=2)
    {
        if(brr[i]>brr[i-1])
            swap(brr[i],brr[i-1]);
        if(brr[i]>brr[i+1]  &&  i<size-1)
            swap(brr[i],brr[i+1]);
    }
}
