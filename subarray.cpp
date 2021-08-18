#include<iostream>
using namespace std;
int main()
{
    int n,s,i,j,k,sum=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n];
    cout<<"Enter elements ->\n";
    for( i=0 ; i<n ;  i++)
        cin>>brr[i];
    cout<<"Enter sum of sub-array : ";
    cin>>s;
    j=k=i=0;
    while(sum<s)
    {
        sum+=brr[i++];
    }
    if(sum==s)
    {
        cout<<"0 "<<i-1;
        return 0;
    }
    while(i<=n)
    {
        if(sum>s)
        {
            sum-=brr[k++];
        }
        else if(sum<s)
        {
            sum+=brr[i++];
        }
        else
        {
            cout<<k+1<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}
