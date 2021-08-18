#include<iostream>
using namespace std;
int main()
{
    int height,i,j,k,c;
    cout<<"Enter height: ";
    cin>>height;
    for(i=1;i<=height;i++)
    {
        c=i;
        for(j=height;j>i;j--)
            cout<<"  ";
        for(j=1;j<=i;j++)
            cout<<c--<<" ";
        c=2;
        for(j=1;j<i;j++)
            cout<<c++<<" ";
        cout<<endl;
    }
    return 0;
}
