#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    int Coin[n];
    for(i=0;  i<n;  i++)
    {
        cin >> Coin[i];
    }
    int Rs;
    cin >> Rs;
    int table[n+1][Rs+1];
    for(i=0;  i<=Rs;  i++)
            table[0][i] = 0;
    for(i=0;  i<=n;  i++)
            table[i][0] = 1;
    
    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=Rs;  j++)
        {
            if(j >= Coin[i-1])
            {
                table[i][j] = table[i-1][j] + table[i][j - Coin[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }

    cout << table[n][Rs];
    return 0;
}