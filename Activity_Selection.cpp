#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return (x.second < y.second);
}


int main()
{
    int n, i, x, y;
    vector<pair<int, int>>  Activities;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        Activities.push_back(make_pair(x, y));
    }

    sort(Activities.begin(), Activities.end(), cmp);

    int MaxAct = 1;
    int e = Activities.front().second;

    for(auto var : Activities)
    {
        if(var.first >= e)
        {
            MaxAct++ ;
            e = var.second;
        }
    }

    cout << MaxAct << endl ;
    return 0;
}