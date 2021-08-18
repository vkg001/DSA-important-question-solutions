#include<iostream>
using namespace std;
bool path(int, int, int maze[5][5], int sol[5][5], int n);
bool isSafe(int i, int j, int maze[5][5], int n);
int main()
{
    int maze[5][5]= {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}},sol[5][5]= {1};
    path(0,0,maze,sol,5);
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            cout<<sol[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}

bool path(int i, int j, int maze[5][5], int solution[5][5], int n)
{
    if(i==n-1  &&  j==n-1)
    {
        solution[i][j]=1;
        return true;
    }
    if(isSafe(i,j,maze,n))
    {
        solution[i][j]=1;
        if(path(i+1,j,maze,solution,n))
        {
            return true;
        }
        if(path(i,j+1,maze,solution,n))
        {
            return true;
        }
        solution[i][j]=0;
        return false;
    }
    return false;
}

bool isSafe(int x, int y, int maze[5][5], int n)
{
    if(x<n  &&  y<n  &&  maze[x][y]==1)
        return 1;
    return 0;
}
