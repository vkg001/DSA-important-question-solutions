#include<bits/stdc++.h>

using namespace std;

template<typename DataType>

class Graph
{
    map<DataType, list<DataType> >  GRAPH;
    map<DataType, int> Indeg;

    public:

    void Insert(DataType x, DataType y, bool Connectivity)
    {
        GRAPH[x].push_back(y);
        Indeg[y]++;
        if(!Indeg[x])
        {
            //cout << "Entry 0 " << endl;
            Indeg[x] = 0;
        }

        if(Connectivity)
        {
            Indeg[x]++;
            GRAPH[y].push_back(x);
        }
    }

    void Topological_Sort()
    {
        queue<DataType>  res_q ;
        for(auto var: Indeg)
        {
            //cout << " xyz " << var.second << endl ;
            if(var.second == 0)
            {
                //cout << "Entry" << endl ;
                res_q.push(var.first);
            }
        }
        while(!res_q.empty())
        {
            DataType var = res_q.front();
            cout << var << "  " ;
            res_q.pop();
            for(auto var2: GRAPH[var])
            {
                Indeg[var2]--;
                if(Indeg[var2] == 0)
                {
                    //cout << "Push " << var2 << endl ;
                    res_q.push(var2);
                }
                
            }
        }
    }
};




/*


        GRAPH   (UNIDIRECTIONAL : UPWARD DIRECTED)

            3                    3 In-Degree 
            ^
          /   \
        4       2                2 In-Degree both
        ^       ^
      /   \   /   \
     5     0 6     1             0 In-Degree each element



*/




int main()
{
    Graph<int> obj ;
    obj.Insert(4,3,false);
    obj.Insert(1,2,false);
    obj.Insert(6,2,false);
    obj.Insert(5,4,false);
    obj.Insert(0,4,false);
    obj.Insert(2,3,false);

    obj.Topological_Sort();

    return 0;
}