#include<bits/stdc++.h>

using namespace std;


class GRAPH
{
    map<int, pair<list<int>, bool>> Graph;
public:

    void Insert(int x, int y)
    {
        Graph[x].first.push_back(y);
        Graph[y].first.push_back(x);
        Graph[x].second = Graph[y].second = false ;
    }

    void MarkVisit(int x)
    {
        Graph[x].second = true;
        for(auto var: Graph[x].first)
        {
            //cout << var << endl ;
            if(!Graph[var].second)
                MarkVisit(var);
        }
    }

    int CompCounter()
    {
        int c = 0;
        for(auto var: Graph)
        {
            if(var.second.second == false)
            {
                c++;
                MarkVisit(var.first);
            }
        }
        return c;
    }

};



/*
                                GRAPH


         ________________________________________________________    
        |                                                        |
        |   Component 1     Component 2         Component 3      |
        |                                                        |
        |   5 ------- 9         -6-               0              |
        |   |                                    / \             |
        |   |                                   /   \            |
        |   |                                  /     \           |
        |   7 ------- 8                       1       2          |
        |                                                        |
        |________________________________________________________|



*/



int main()
{
    GRAPH obj;
    int x;
    obj.Insert(9,5);
    obj.Insert(7,5);
    obj.Insert(7,8);
    obj.Insert(6,6);
    obj.Insert(0,1);
    obj.Insert(0,2);

    x = obj.CompCounter();
    cout << x << endl ;

    return 0;
}