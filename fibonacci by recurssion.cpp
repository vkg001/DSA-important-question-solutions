#include<iostream>
using namespace std;
void fib(int n, int pos, int t1, int t2)
{
    int x=t1+t2;
    if(pos<=n)
    {
        cout<<x<<"  ";
        fib(n,pos+1,t2,x);
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    if (n==2)
        cout<<"0 1";
    else if(n==1)
        cout<<"0";
    if(n>2)
    {
        cout<<"0  1  ";
        fib(n,2,0,1);
    }

    return 0;
}
