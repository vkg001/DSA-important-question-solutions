#include<iostream>
using namespace std;

int maze(int n, int i=0, int j=0)
{
    if(i>=n  ||  j>=n)   return 0;
    if(i==n-1  &&  j==n-1)    return 1;
    return (maze(n,i+1,j)+maze(n,i,j+1));
}

int main()
{
    int n,paths;
    cout<<"Enter size of n: ";
    cin>>n;
    paths=maze(n);
    cout<<"Number of paths to reach end are "<<paths;
    return 0;
}
