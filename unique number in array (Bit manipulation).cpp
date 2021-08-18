#include<iostream>
using namespace std;

int uniquenumber(int* brr, int size)
{
    int i,lol=0;
    for(i=0;i<size;i++)
    {
        lol=lol^brr[i];
    }
    return lol;
}

int main()
{
    int n,brr[100],i;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    cout<<uniquenumber(brr,n);
    return 0;
}
