#include<bits/stdc++.h>

using namespace std;
map<int, int> visited;

int Down_to_Zero(int n) 
{
    if(visited[n])
        return visited[n];


    if(n < 4)
        return n;

    int i;
    visited[n] = INT_MAX;
    for(i=1;  (i*i) <=n   ;   i++)
    {
        visited[n] = min(visited[n], 1 + Down_to_Zero(n - (i*i)));
    }
    return visited[n];
}

int main()
{
    int n;
    cin >> n;
    cout << Down_to_Zero(n) << endl ;
    return 0;
}