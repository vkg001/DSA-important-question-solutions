#include<iostream>
using namespace std;
int main()
{
    int side,i,j,k;
    cout<<"Enter Side: ";
    cin>>side;
    for(i=0;i<side;i++)
    {
        for(j=side-1;j>=i;j--)
            cout<<"  ";
        for(k=0;k<side;k++)
            cout<<"* ";
        cout<<endl;
    }
    return 0;
}
