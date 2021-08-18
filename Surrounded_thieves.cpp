// O thieves
// X Police

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row, col, i, j;
    char ch;
    cin >> row >> col;
    char grid[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin >> grid[i][j];
        }
    }
    for(i=0; i<row; i++)
    {
        if(i==0 || i==row-1)
        {
            for(j=0; j<col; j++)
        {
            if(grid[i][j]=='O')
                grid[i][j] = '#';
        }
        }
        else
        {
            if(grid[i][0] == 'O')
                grid[i][0] = '#';
            if(grid[i][col-1] == 'O')
                grid[i][col-1] = '#';
        }
    }
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(grid[i][j] == 'O')
                grid[i][j] = 'X';
            else if(grid[i][j] == '#')
                grid[i][j] = 'O';
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}