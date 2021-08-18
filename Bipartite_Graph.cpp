#include<bits/stdc++.h>

using namespace std;

map<int, list<int>>  Edges;
map<int, short int>  Color;

bool ChangeColor(int n)
{
    if(Color[n] == 1)
    {
        return false;
    }
    Color[n] = 0 ;
    for(auto var: Edges[n])
    {
        if(Color[var] != 0)
        {
            Color[var] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}


bool CheckBipartite()
{
    for(auto var: Edges)
    {
        if(var.second.front() == -1)
        {
            if(!ChangeColor(var.second.front()))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m, p;
    cin >> p;
    
    while(p--)
    {
        cin >> n >> m ;
        Edges[n].push_back(m);
        Edges[m].push_back(n);
        Color[n] = Color[m] = -1;
    }

    if(!CheckBipartite())
    {
        cout << "Not Bipartite \n" ;
        return 0;
    }
    cout << "Bipartite \n" ;
    return 0;
}