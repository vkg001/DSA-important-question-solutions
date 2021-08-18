#include<iostream>
#include<climits>
#include<string>

using namespace std;

const int N = 5000;
int table[N][N];

bool isPalindrome(int i,  int j,  string &s)
{
    while (i < j)
    {
        if(s[i] != s[j])
            return false;
        i++;    j--;
    }
    return true;
}

int Solve(int i,  int j,  string &s)
{
    if(i >= j)
        return 0;
    if(table[i][j] != -1)
        return table[i][j];
    if(isPalindrome(i, j, s))
        return 0;
    int ans = INT_MAX, left, right;
    for(int k = i;  k < j;  k++)
    {
        if(table[i][k] != -1)
        {
            left = table[i][k];
        }
        else
        {
            left = Solve(i, k, s);
            table[i][k] = left;
        }
        if(table[k+1][j] != -1)
        {
            right = table[k+1][j];
        }
        else
        {
            right = Solve(k+1, j, s);
            table[k+1][j] = right;
        }
        int temp = left + right + 1;
        ans = min(ans, temp);
    }
    table[i][j] = ans;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    for(int i=0;  i<s.size();  i++)
        for(int j=0;  j<s.size();  j++)
            table[i][j] = -1;
    cout << Solve(0, s.size()-1, s);
    return 0;
}