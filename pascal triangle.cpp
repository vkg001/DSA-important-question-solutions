#include<iostream>
using namespace std;
int arr[500][500];
int main()
{
    int rows,i,element,j,temp;
    cout<<"Enter number of rows: ";
    cin>>rows;
    arr[0][0]=1;
    for(i=0;i<rows;i++)
    {
        cout<<"1 ";
        arr[i][0]=1;
        for(j=1;j<i;j++)
        {
            element=arr[i-1][j]+arr[i-1][j-1];
            cout<<element<<" ";
            arr[i][j]=element;
        }
        cout<<endl;
    }
    return 0;
}
