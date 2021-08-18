#include<iostream>
using namespace std;

int chkBit(int* brr, int pos, int n)
{
    int i,b=(1<<pos),xyz=0;
    for(i=0;i<n;i++)
    {
        if((b & brr[i])==1)
            xyz=xyz^brr[i];
    }
    cout<<xyz<<endl;
    return xyz;
}

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
    int n,brr[100],i,xyz,temp;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    temp=xyz=uniquenumber(brr,n);
    int pos=0,setBit=0;
    while((setBit & 1) !=1)
    {
        pos++;
        xyz>>1;
        setBit=xyz;
    }
    cout<<(temp^chkBit(brr,pos-1,n));
    return 0;
}
