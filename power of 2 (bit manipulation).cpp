#include<iostream>
using namespace std;
bool chk(int n)
{
    int x;
    x=n-1;
    x=(x&n);
    if(x==0)   return true;
    return false;
}
int main()
{
    int n,f;
    cout<<"Enter number: ";
    cin>>n;
    if(chk(n))   cout<<"Number is in power of 2.";
    else   cout<<"Number is not in power of 2.";
    return 0;
}
