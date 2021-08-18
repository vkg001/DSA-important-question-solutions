#include<iostream>
using namespace std;
int main()
{
    int height,i,j,c=1,k;
    cout<<"Enter height of pyramid: ";
    cin>>height;
    for(i=0;i<height;i++)
    {
        c=1;
        for(j=i;j<height;j++)
            cout<<" ";
        for(k=0;k<=i;k++)
            cout<<c++<<" ";
        cout<<endl;
    }
    return 0;
}
