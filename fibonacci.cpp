#include<iostream>
using namespace std;
void fib(int n);
int main()
{
    int n;
    cout<<"Enter number of terms : ";
    cin>>n;
    //cout<<sizeof(n);
    fib(n);
    return 0;
}

void fib(int n)
{
    int t1,t2,nxt,i;
    t1=0;
    t2=1;
    for(i=1;i<=n;i++)
    {
        cout<<t1<<"  ";
        nxt=t1+t2;
        t1=t2;
        t2=nxt;
    }
    return;
}
