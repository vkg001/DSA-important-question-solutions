#include<iostream>
using namespace std;
void nCr(int,int);
int main()
{
    int n,r;
    cout<<"Enter n & r : ";
    cin>>n>>r;
    nCr(n,r);
    return 0;
}

void nCr(int n, int r)
{
    int i,j,res=1,res1=1;
    j=n;
    for(i=1;i<=r;i++)
    {
        res*=j;
        j--;
        res1*=i;
    }
    res/=res1;
    cout<<res;
    return;
}
