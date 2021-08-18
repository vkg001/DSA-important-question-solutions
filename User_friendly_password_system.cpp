#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

long app_char;
long org_pass;
long con_pass;
const int M = 1e9+7;
const int P = 131;

void HashFunc(string s, int ch)
{
    int len = s.size();
    int i = 0;
    long long temp = 0, temp2 = 0;
    while(i < len)
    {
        temp += s[i]*(pow(P, len-(i+1)));
        temp2 += s[i]*(pow(P, len-i));
        i++;
    }
    if(ch == 1)
    {
        org_pass = temp % M ;
        app_char = temp2 % M ;
        org_pass++;
    }
}


vector<int> AuthPass(vector<pair<char, string>> queries)
{
    vector<int> res;
    int i, x ;
    i = 0;
    for(auto str: queries)
    {
        if(str.first == 'a')
        {
            con_pass = stoi(str.second);
            if(con_pass == org_pass  ||  (con_pass > app_char  &&  con_pass < app_char+255))
            {
                res.push_back(1);
            }
            else
            {
                res.push_back(0);
            }
        }
        else
        {
            HashFunc(str.second, 1);
        }
    }
    return res;
}

int main()
{
    int q;
    string s;
    char c;
    vector<pair<char, string>> queries;
    cin >> q;
    while(q--)
    {
        cin >> c;
        cin >> s;
        queries.push_back({c, s});
    }
    vector<int> res = AuthPass(queries);
    for(auto num: res)
        cout << num << endl ;
    return 0;
}