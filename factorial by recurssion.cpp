#include<iostream>
using namespace std;

int fac(int n)
{
    if(n==0)   return 1;
    return (n*(fac(n-1)));
}

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Factorial is "<<fac(n);
    return 0;
}
