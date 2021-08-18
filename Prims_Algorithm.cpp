


//  NOT COMPLETED YET



#include<bits/stdc++.h>

using namespace std;

map<int, bool> visited ;
const int N = 1e5;
map<pair<int, int> , int >  adj_mat;
set<pair<int, int>> mst;
map<int, list<int>> conn;
map<int, list<int>> parent;


void Prims_Algo(int n)
{
    //cout << "Enter" << endl;
    if(mst.empty())
        return ;
    for(auto var: conn[n])
    {
        if(visited[var])    continue;
        mst.insert(make_pair(adj_mat[{n,var}], var));
        visited[var] = true;
    }
    pair<int, int> temp = *(mst.begin());
    mst.erase(mst.begin());
    cout << temp.second << "  " << temp.first << endl;
    Prims_Algo(temp.second);
}


int main()
{
    //cout << "Enter main " << endl;
    int n, w, x, y;
    cin >> n;
    while(n--)
    {
        //cout << "Iter" << endl;
        cin >> w >> x >> y ;
        adj_mat[{x,y}] = w;
        //cout << "Pass 1" << endl;
        conn[x].push_back(y);
        //cout << "Pass 2" << endl;
        conn[y].push_back(x);
        //cout << "Pass 3" << endl;
        visited[x] = visited[y] = false ;
        //cout << "Stuck" <<endl;
    }
    // Initial Element to start
    cin >> n;
    visited[n] = true;
    mst.insert(make_pair(0,n));
    Prims_Algo(n);
    return 0;
}