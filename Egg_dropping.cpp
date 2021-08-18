
// TESTED ON GFG

#include<iostream>
#include<climits>

using namespace std;

const int N = 1e3;
int table[N][N];

int Solve(int floor, int egg)
{
    if(floor < 2)
        return floor;
    if(egg == 1)
        return floor;
    if(table[floor][egg] != 0)
        return table[floor][egg];


    int ans = INT_MAX,  temp;
    for(int k = 1;  k <= floor;  k++)
    {
        temp = 1 + max(Solve(k-1, egg-1) ,  Solve(floor-k, egg));
        ans = min(ans, temp);
    }
    table[floor][egg] = ans;
    //cout << floor << " | " << egg << endl ;
    return ans;
}

int main()
{
    int floor, egg;
    cin >> floor >> egg ;
    cout << Solve(floor, egg) << endl;
    return 0;
}