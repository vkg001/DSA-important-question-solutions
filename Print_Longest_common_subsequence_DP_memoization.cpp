#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    string str, str1, temp;
    cin >> str >> str1;
    int table[str.size()+1][str1.size()+1];
    for(i=0;  i<=str.size();  i++)
        table[i][0] = 0;
    for(i=0;  i<=str1.size();  i++)
        table[0][i] = 0;
    
    for(i=1;  i<=str.size();  i++)
    {
        for(j=1;  j<=str1.size();  j++)
        {
            if(str[i-1] == str1[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else
            {
                table[i][j] = max(table[i-1][j] ,  table[i][j-1]);
            }
        }
    }
    
    i = str.size();     j = str1.size();

    while(table[i][j] > 0)
    {
        if(str[i-1] == str1[j-1])
        {
            temp.push_back(str[i-1]);
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

    i = temp.size()-1 ;
    
    while(i >= 0)
        cout << temp[i--];
    
    cout << endl;
    
    return 0;
}