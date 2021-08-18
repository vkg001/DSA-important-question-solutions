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

    void Detect_Cycle()
    {
        int c = 0;
        queue<DataType>  res_q ;
        vector<DataType>  Check ;
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
            Check.push_back(var) ;
            c++;
            res_q.pop();
            for(auto var2: GRAPH[var])
            {
                Indeg[var2]--;
                if(Indeg[var2] == 0)
                {
                    res_q.push(var2);
                }
                
            }
            
        }
        if(Check.size() == GRAPH.size())
            cout << "Cycle Absent. \n" << c << endl ;
        else
            cout << "Cycle Present. \n" << c << endl ;
    }
};




/*


        GRAPH   1

            3                    3 In-Degree 
            ^
          /   \
        4       2                2 In-Degree both
        ^       ^
      /   \   /   \
     5     0 6     1             0 In-Degree each element





        GRAPH 2

    5 <---- 3 ----> 4            Unidirectional Link
           / \
          /   \
         0     2                 Unidirectional Link
          \   /
           \ /
            1                    Unidirectional Link



*/




int main()
{
    Graph<int> obj ,  obj2;

//  1ST GRAPH OBSERVATION    

    obj.Insert(4,3,false);
    obj.Insert(1,2,false);
    obj.Insert(6,2,false);
    obj.Insert(5,4,false);
    obj.Insert(0,4,false);
    obj.Insert(2,3,false);

    obj.Detect_Cycle();

//  2ND GRAPH OBSERVATION

    obj2.Insert(3,4,false);
    obj2.Insert(3,5,false);
    obj2.Insert(3,0,false);
    obj2.Insert(2,3,false);
    obj2.Insert(0,1,false);
    obj2.Insert(1,2,false);

    obj2.Detect_Cycle();

    return 0;
}