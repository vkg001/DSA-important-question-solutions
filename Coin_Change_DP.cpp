#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, c, amount, x, i, j;
    vector<int> Coins;
    cin >> n;
    c = n;
    while(n--)
    {
        cin >> x;
        Coins.push_back(x);
    }
    //sort(Coins.begin(), Coins.end());
    cin >> amount;

    // c is number of elements 
    int table[c+1][amount+1];

    for(i=0; i<=amount;  i++)
        table[0][i] = 0;

    for(i=0;  i<=c;  i++)
        table[i][0] = 1;

    for(i=1;  i<=c;  i++)
    {
        for(j=1;  j<=amount;  j++)
        {
            if(j >= Coins[i-1])
            {
                table[i][j] = table[i-1][j] + table[i][j - Coins[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }
    cout <<  table[c][amount];
    return 0;
}