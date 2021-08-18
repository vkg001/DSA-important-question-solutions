#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int n, w, x, y, i, src;
    vector<vector<int>> edge;
    cin >> n;
    i = n;
    vector<int> distance(n,INF);
    while (n--)
    {
        cin >> x >> y >> w;
        edge.push_back({w,x,y});
    }
    n = i;
    cin >> src;
    distance[src] = 0;
    for(i=0; i<n; i++)
    {
        for(auto var: edge)
        {
            w = var[0];
            x = var[1];
            y = var[2];
            distance[y] = min(distance[y], w + distance[x]);
        }
    }
    for(auto var: distance)
    {
        if(var < INF)
            cout << var << " ";
    }
    cout << endl;
    return 0;
    
}