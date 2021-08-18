#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    int i, j;
    cin >> a >> b;
    int table[a.size()+1][b.size()+1];
    
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
    int lcs = table[i-1][j-1];
    cout << "INS " << b.size()-lcs << endl << "DEL " << a.size()-lcs << endl;
    return 0;
}