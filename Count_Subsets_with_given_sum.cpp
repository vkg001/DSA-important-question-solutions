#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, sum;
    cin >> n;
    int arr[n];
    for(i=0;  i<n;  i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    int table[n+1][sum+1];
    for(i=0;  i<=sum;  i++)
        table[0][i] = 0;
    for(i=0;  i<=n;  i++)
        table[i][0] = 1;
    
    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=sum;  j++)
        {
            if(j >= arr[i-1])
            {
                table[i][j] = table[i-1][j] + table[i-1][j- arr[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }
    cout << table[n][sum] << endl;
    return 0;
}