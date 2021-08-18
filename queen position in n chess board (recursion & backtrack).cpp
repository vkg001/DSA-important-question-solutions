#include<iostream>
using namespace std;

bool isSafe(int i, int j, int size, int** chess)
{
    int row,col;
    for(col=i-1;col>=0;col--)
        if(chess[col][j]==1)   return false;
    col=i-1;
    row=j-1;
    while(col>=0  &&  row>=0)
    {
        if(chess[col][row]==1)   return false;
        row--;
        col--;
    }
    row=i-1;
    col=j+1;
    while(row>=0  &&  col<size)
    {
        if(chess[row][col]==1)   return false;
        row--;
        col++;
    }
    return true;
}


bool qinsert(int i, int size, int** chess)
{
    if(i>=size)   return true;
    for(int col=0;col<size;col++)
    {
        if(isSafe(i,col,size,chess))
        {
            chess[i][col]=1;
            if(qinsert(i+1,size,chess))
            {
                return true;
            }
            chess[i][col]=0;
        }
    }
    return false;
}



int main()
{
    int n;
    cout<<"Enter size of chess: ";
    cin>>n;
    int** chess=new int *[n];
    for(int i=0;i<n;i++)
    {
        chess[i]=new int [n];
        for(int j=0;j<n;j++)
            chess[i][j]=0;
    }
    if(qinsert(0,n,chess))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<chess[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
