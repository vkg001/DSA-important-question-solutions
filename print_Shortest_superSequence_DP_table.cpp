/*
INPUT :
AGGTABFGH
GXTXAYB

EXPECTED OUTPUT
AGGXTXAYBFGH

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    int i, j;
    cin >> a >> b;

    int table[a.size()+2][b.size()+2];

    for(i=0;  i<=a.size();  i++)
        table[i][0] = 0;
    for(i=0;  i<=b.size();  i++)
        table[0][i] = 0;

    for(i=1;  i<=a.size();  i++)
    {
        for(j=1;  j<=b.size();  j++)
        {
            if(a[i-1] == b[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else
            {
                table[i][j] = max(table[i-1][j],  table[i][j-1]);
            }
        }
    }
    i = a.size();
    j = b.size();
    string ans;
    //cout << table[i][j];
    while(table[i][j] != 0)
    {
        if(a[i-1] == b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;    j--;
        }
        else
        {
            if(table[i-1][j] > table[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    int k = ans.size()-1;
    i = j = 0;
    
    while(i<a.size()  and   j<b.size()  and  k>=0)
    {
        if(a[i] == b[j]  and  b[j] == ans[k])
        {
            cout << a[i] ;
            i++;    j++;    k--;
        }
        else
        {
            if(a[i] != ans[k])
                cout << a[i++];

            if(b[j] != ans[k])
                cout << b[j++];
        }
    }

    while(i<a.size())
        cout << a[i++];
    
    while(j<b.size())
        cout << b[j++];

    return 0;
}