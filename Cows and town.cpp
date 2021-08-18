/*
A truck carrying cows travelling towards a town but its fuel tank has been punctured and
hence it is consuming fuel @ 1L/Km some fuel stations are present on the road towards town
that has some fuel. 
    Calculate minimum amount of stops at which truck has to be refueled .
Note 1: Fuel tank of truck can hold any amount of fuel at  a time.

Input Format :
Line 1 : 3 space seperated integers
        1st Initial Fuel present in truck
        2nd Distance of truck from town
        3rd Number of fuel stations

Next n Consecutive lines contains
    Fuel at the station and its distance from town ( 2 space seperated integers )

*/

#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return (x.first > y.first);
}


int main()
{
    int curr_Fuel, curr_Distance, Num_Fuel_Stations, x, y, Stops = 0;
    vector<pair<int, int>>  Distance_and_Fuel;
    cin >> curr_Fuel >> curr_Distance >> Num_Fuel_Stations ;
    while(Num_Fuel_Stations--)
    {
        cin >> x >> y ;
        Distance_and_Fuel.push_back({x, y});
    }
    sort(Distance_and_Fuel.begin(), Distance_and_Fuel.end(), cmp);
    
    vector<pair<int, int> > :: iterator prev, it = Distance_and_Fuel.begin() ;

    int Distance, MaxfuelDis;
    int  maxFuel, f=1;
    
    while(curr_Distance > 0)
    {
        maxFuel = 0;

        Distance = curr_Distance - it->first ;
        prev = it ;
        while(Distance <= curr_Fuel   &&   it != Distance_and_Fuel.end())
        {
            if(maxFuel < it->second)
            {
                MaxfuelDis = Distance ;
                maxFuel = it->second ;
            }

            if(curr_Fuel + maxFuel >= curr_Distance)
            {
                f=0;
                break;
            }

            it++;
            Distance = curr_Distance - it->first ;
        }
        
        Stops ++;

        if(f==0)
        {
            break;
        }
        curr_Fuel = (curr_Fuel - MaxfuelDis) + maxFuel ;
        curr_Distance -= MaxfuelDis ; 
    }

    cout << Stops << endl ;

    return 0;

}