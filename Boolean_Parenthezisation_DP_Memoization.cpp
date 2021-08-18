#include<iostream>
#include<string>

using namespace std;

const int N = 1000;
int table[N][N][2];

int Solve(string &s, int i, int j, bool req)
{
    if(i > j)
        return false;
    
    if(table[i][j][req] != -1)
        return table[i][j][req];
    
    if(i == j)
    {
        if(req == true)
            table[i][j][req] = (s[i] == 'T');
        else
            table[i][j][req] = (s[i] == 'F');
        
        return table[i][j][req];
    }
    int temp, ans = 0;
    for(int k = i+1;  k < j;  k = k+2)
    {
        int lf = Solve(s, i, k-1, false);
        int lt = Solve(s, i, k-1, true);
        int rf = Solve(s, k+1, j, false);
        int rt = Solve(s, k+1, j, true);
        switch (s[k])
        {
        case '|':
            temp = lf*rt + lt*rf + lt*rt;
            break;
        case '&':
            temp = lt*rt;
            break;
        case '^':
            temp = lf*rt + lt*rf ;
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
        ans += temp;
    }
    table[i][j][req] = ans;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    for(int i=0;  i<s.size();  i++)
        for(int j=0;  j<s.size();  j++)
            for(int k=0;  k<2;  k++)
                table[i][j][k] = -1;
    cout << Solve(s, 0, s.size()-1, true);
    return 0;
}