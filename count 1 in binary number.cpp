#include<iostream>
using namespace std;
int main()
{
    int n,x,count=0;
    cout<<"Enter number: ";
    cin>>n;
    x=n-1;
    while(n!=0)
    {
        count++;
        n=(x&n);
        x=n-1;
    }
    cout<<"Ones in given number are "<<count<<endl;
    return 0;
}
