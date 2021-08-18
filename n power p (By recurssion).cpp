#include<iostream>
using namespace std;

int power(int n, int p)
{
    if(p==0)   return 1;
    return (n*(power(n,p-1)));
}

int main()
{
    int n,p;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Enter power: ";
    cin>>p;
    cout<<n<<"^"<<p<<" is "<<power(n,p)<<endl;
    return 0;
}
