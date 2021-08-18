#include<iostream>
using namespace std;
int main()
{
    int rows,cols,i,j,c=1;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter cols: ";
    cin>>cols;
    for(i=0;i<rows;i++)
    {
        if(i%2==0)  c=1;
        else  c=0;
        for(j=0;j<=i;j++)
        {
            cout<<c<<" ";
            if(c==0)  c=1;
            else   c=0;
        }
        cout<<endl;
    }
    return 0;
}
