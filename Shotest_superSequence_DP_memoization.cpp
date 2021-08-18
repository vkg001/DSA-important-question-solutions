#include<bits/stdc++.h>

using namespace std;

int table[5000][5000];

int LCS(string &str1, string &str2, int idx1, int idx2)
{
    if(idx1 < 0   ||   idx2 < 0)
        return 0;
    
    if(table[idx1][idx2] != -1)
    {
        return table[idx1][idx2];
    }

    if(str1[idx1] == str2[idx2])
    {
        table[idx1][idx2] = 1 + LCS(str1, str2, idx1-1, idx2-1);
        return table[idx1][idx2];
    }
    table[idx1][idx2] = max(LCS(str1, str2, idx1-1, idx2),  LCS(str1, str2, idx1, idx2-1));
    return table[idx1][idx2];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2 ;
    for(int i=0;  i<str1.size(); i++)
        for(int j=0;  j<str2.size();  j++)
            table[i][j] = -1;
    int lcs = LCS(str1, str2, str1.size()-1, str2.size()-1);
    cout << (str1.size() + str2.size() - lcs) << endl;
    return 0;
}