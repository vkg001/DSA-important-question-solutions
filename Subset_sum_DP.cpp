#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, x, k;
    vector<int> arr;
    cin >> n;
    for(i=0;  i<n;  i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    cin >> k;
    
    sort(arr.begin(), arr.end());

    bool table[n+1][k+1];

    //cout << "PASS 1" << endl;
    for(i=0;  i<=k;  i++)
        table[0][i] = false;
    for(i=0;  i<=n;  i++)
        table[i][0] = true;
    
    //cout << "PASS 2" << endl;
    for(i=1;  i<=n;  i++)
    {
        for(j=1;  j<=k;  j++)
        {
            if(j >= arr[i-1])
            {
                table[i][j] = table[i-1][j]  ||  table[i-1][j-arr[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
            //cout << table[i][j] << " ";
        }
        //cout << endl;
    }
    if(table[n][k] == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    

    return 0;
}