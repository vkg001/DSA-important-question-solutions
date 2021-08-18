#include<iostream>
using namespace std;
int main()
{
    int rows,c,i,j,k,l;
    cout<<"Enter rows: ";
    cin>>rows;
    for(i=0;i<rows/2;i++)
    {
        for(j=0;j<=i;j++)
            cout<<"* ";
        for(c=0;c<2;c++)
        for(k=(rows/2)-1;k>i;k--)
            cout<<"  ";
        for(j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }
    for(i=0;i<rows/2;i++)
    {
        for(j=(rows/2);j>i;j--)
            cout<<"* ";
        for(c=0;c<2;c++)
        for(k=0;k<i;k++)
            cout<<"  ";
        for(j=(rows/2);j>i;j--)
            cout<<"* ";
        cout<<endl;
    }
    return 0;
}
