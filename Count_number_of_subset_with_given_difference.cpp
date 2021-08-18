#include<bits/stdc++.h>

using namespace std;

/*

sum of subset 1 : s1
sum of subset 2 : s2

s1 - s2 = diff ......(1)    {GIVEN}
s1 + s2 = sum of arr .......(2) 
Adding (1) & (2)
2s1 = (diff + sum of arr)
s1 = (diff + sum of arr) / 2

*/


int main()
{
    int n, i, j, diff, sum = 0;
    cin >> n;
    int arr[n];
    for(i=0;  i<n;  i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> diff;
    sum = (sum + diff) / 2 ;

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
                table[i][j] = table[i-1][j]  +  table[i-1][j-arr[i-1]];
            }
            else
            {
                table[i][j] = table[i-1][j];
                //cout << i-1 << " | " << table[i][j] << endl;
            }
        }
    }
    
    
    for(i=0;  i<=n;  i++)
    {
        for(j=0;  j<=sum;  j++)
        {
            cout << table[i][j] << " " ;
        }
        cout << endl;
    }
    

    cout << table[n][sum] << endl;
    return 0;    
}