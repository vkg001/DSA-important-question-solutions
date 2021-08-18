#include<bits/stdc++.h>

using namespace std;

map<int, int>  sets, sizes;

int Find_set(int x)
{
    if(x == sets[x])
        return x;
    return (Find_set(sets[x]));
}


void Merge(int x, int y)
{
    int a, b;
    a = Find_set(x);
    b = Find_set(y);
    if(a != b   &&   sizes[a] < sizes[b])
    {
        swap(a, b);
    }
    sets[b] = a;
    sizes[a] += sizes[b] ;
}

int main()
{
    int n, x, y;
    cin >> n;
    while(n--)
    {
        cin >> x;
        sets[x] = x;
        sizes[x]++;
    }
    cin >> x >> y;
    Merge(x, y);
    cin >> x >> y;
    Merge(x, y);
    cout << sets[y] << endl ;
}