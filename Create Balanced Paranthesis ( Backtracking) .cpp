#include<bits/stdc++.h>

using namespace std;

vector<string> result;


void ParanthesisGenerator(int open, int close, string &str)
{
    if(open == 0    &&    close == 0)
    {
        result.push_back(str);
        return;
    }

    if(open > 0)
    {
        str.push_back('(');
        ParanthesisGenerator(open-1, close, str);
        str.pop_back();
    }

    if(close > open)
    {
        str.push_back(')');
        ParanthesisGenerator(open, close-1, str);
        str.pop_back();
    }


}


int main()
{
    int n;
    cin >> n;
    string s;

    ParanthesisGenerator(n, n, s);

    for(auto var: result)
    {
        cout << var <<endl;
    }

    return 0;
}
