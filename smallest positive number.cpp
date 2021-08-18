#include<iostream>
using namespace std;
int main()
{
    int i,n,temp;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n],crr[n];
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
    {
        crr[i]= -1;
        cin>>brr[i];
    }
    for(i=0;i<n;i++)
    {
        temp=brr[i];
        crr[temp]=1;
    }
    for(i=0;i<n;i++)
        if(crr[i]== -1)
             break;
    cout<<i;
    return 0;
}
