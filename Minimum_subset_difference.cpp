#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, orgsum = 0, sum;
    cin >> n;
    int arr[n];
    for(i=0;  i<n;  i++)
    {
        cin >> arr[i];
        orgsum += arr[i];
    }
    sum = orgsum ;
    bool table[n+1][sum+1];

    for(i=0;  i<=sum;  i++)
        table[0][i] = false;
    for(i=0;  i<=n;  i++)
        table[i][0] = true;
    
    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=sum;  j++)
        {
            if(j >= arr[i-1])
            {
                table[i][j] = table[i-1][j]  ||  table[i-1][j-arr[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
                //cout << i-1 << " | " << table[i][j] << endl;
            }
        }
    }

    /*
    for(i=0;  i<=n;  i++)
    {
        for(j=0;  j<=sum;  j++)
        {
            cout << table[i][j] << " " ;
        }
        cout << endl;
    }
    */

    int diff = INT_MAX;
    for(i=0;  i<=orgsum/2;  i++)
    {
        //cout << i << " | " << table[n][i] << endl ;
        if(table[n][i])
            diff = min(diff, abs(orgsum - (2*i)));
        //cout << diff << " ";
    }
    //cout << endl;
    cout << diff << endl;
    return 0;
}