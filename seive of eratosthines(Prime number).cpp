#include<iostream>
using namespace std;

long long *brr;
int main()
{
    long long n,i;
    cout<<"Enter number: ";
    cin>>n;

    brr= new long long [n];

    for(i=2;i<=n;i++)
    {
        if(brr[i]==0)
        for(long long j=i*i;j<=n;j+=i)
            if(j%i==0)   brr[j]=1;
    }
    for(i=1;i<=n;i++)
        if(brr[i]==0)   cout<<i<<"  ";
    return 0;
}
