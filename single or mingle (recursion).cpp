#include<iostream>
using namespace std;

int ways(int);

int main()
{
    int n;
    cout<<"Enter number of persons: ";
    cin>>n;
    cout<<ways(n);
    return 0;
}

int ways(int n)
{
    if(n==0)   return 0;
    else if(n==1)   return 1;
    else if(n==2)   return 2;
    return (ways(n-1)+(n-1)*ways(n-2));
}
