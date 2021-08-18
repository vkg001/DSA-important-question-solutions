#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, len, i, j;
    cin >> n;
    int price[n];
    for(i=0;  i<n;  i++)
        cin >> price[i];
    
    int table[n+1][n+1];
    for(i=0;  i<=n;  i++)
    {
        table[0][i] = 0;
        table[i][0] = 0;
    }
    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=n;  j++)
        {
            if(j >= i)
            {
                table[i][j] = max(table[i-1][j], price[i-1] + table[i][j-i]);
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }
    cout << table[n][n] << endl;
    return 0;
}