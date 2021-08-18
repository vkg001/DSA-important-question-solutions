#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k = 0, x;
    cin >> n;
    int arr[n];
    for(i=0;  i<n;  i++)
    {
        cin >> arr[i];
        k += arr[i];
    }
    if(k%2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    k/=2;
    bool table[n+1][k+1];
    for(i=0;  i<=k;  i++)
    {
        table[0][i] = false;
    }
    for(i=0;  i<=n;  i++)
    {
        table[i][0] = true;
    }

    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=k;  j++)
        {
            if(j >= arr[i])
            {
                table[i][j] = table[i-1][j]  ||  table[i-1][j-arr[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }
    if(table[n][k])
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}