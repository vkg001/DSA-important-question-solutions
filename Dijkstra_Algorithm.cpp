#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int,int>>>   elements(n+1);
    vector<int> distance(n+1,N);
    set<pair<int, int>> s;
    while(n--)
    {
        int u,v,w;
        cin >> w >> u >> v;
        elements[u].push_back({w,v});
        elements[v].push_back({w,u});
    }
    cin >> n;
    s.insert(make_pair(0,n));
    distance[n] = 0;
    while(!s.empty())
    {
        //cout << "OUT" << endl;
        set<pair<int, int>>::iterator temp = s.begin();
        s.erase(temp);
        int temp1 = temp->second;

        for(auto var: elements[temp1])
        {
            if(distance[var.second] > var.first + distance[temp1])
            {
                //cout << " temp " << temp1->second << " | ";
                //cout <<var.second << " | " << distance[var.second] << " | " ;
                s.erase(make_pair(distance[var.second], var.second));
                distance[var.second] = var.first + distance[temp1];
                //cout << var.first << " | " << distance[temp1->second] << endl;
                s.insert(make_pair(distance[var.second], var.second));
            }
        }
    }
    for(auto var: distance)
    {
        if(var < N)
            cout << var << " ";
    }
    return 0;
}