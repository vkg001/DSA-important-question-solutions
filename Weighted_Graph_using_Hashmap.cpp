#include<bits/stdc++.h>

using namespace std;

class Graph
{
    // First string will store initial city
    // String in list will store target city
    // Int in list will store distance
    unordered_map<string, list<pair<string, int> > >  GRAPH ; 

    public:
        void Insert(string sourceCity, string TargetCity, int Distance, bool Connectivity)
        {
            // Conectivity means unidirectional or bidirectional
            GRAPH[sourceCity].push_back(make_pair(TargetCity, Distance));
            if(Connectivity == true)
            {
                GRAPH[TargetCity].push_back(make_pair(sourceCity, Distance));
            }
        }



        void Display()
        {
            for(auto Element: GRAPH)
            {
                cout << "Roads are available from " << Element.first << " to " ;
                for(auto City: Element.second)
                {
                    cout << "\nCity: " << City.first <<" | Distance: " << City.second ;
                }
                cout << endl << endl << endl ;
            }
        }
};


int main()
{
    Graph obj;
    string   Agra     =    "Agra" ;
    string   Mathura  =    "Mathura" ;
    string   Aligarh  =    "Aligarh" ;
    string   Hathras  =    "Hathras" ;
    string   Delhi    =    "Delhi" ;

    obj.Insert(Agra, Delhi, 150, true);
    obj.Insert(Agra, Aligarh, 100, true);
    obj.Insert(Hathras, Agra, 70, false);
    obj.Insert(Hathras, Aligarh, 40, false);
    obj.Insert(Hathras, Mathura, 60, true);
    obj.Insert(Mathura, Agra, 40, false);

    obj.Display();

    return 0;
}