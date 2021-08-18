#include<iostream>
using namespace std;
int main()
{
    int i,n,min=32767,brr[100000],check[100000],x;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    for(i=0;i<100000;i++)
        check[i]= -1;
    for(i=0;i<n;i++)
    {
        x=brr[i];
        if(check[x]!= -1   &&   min>check[x])  min=check[x];
        else   check[x]=i;
    }
    cout<<"Minimum index is "<<min+1<<endl;
    return 0;
}
