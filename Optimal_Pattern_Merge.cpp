#include<bits/stdc++.h>
#include<queue>
using namespace std;

bool cmp(int x, int y)
{
    return (x < y);
}

int main()
{
    priority_queue<int, vector<int>, greater<int> > STL_Q;
    int n, x, cost = 0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        STL_Q.push(x);
    }

    while(!STL_Q.empty())
    {
        n = STL_Q.top();
        STL_Q.pop();
        if(STL_Q.empty())     break;
        x = STL_Q.top();
        STL_Q.pop();
        cost += x+n ;
        STL_Q.push(n+x);
    }

    cout <<  cost  << endl;

    return 0;
}