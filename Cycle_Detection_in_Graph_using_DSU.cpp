#include<bits/stdc++.h>

using namespace std;

map<int, int>  DS, sz;

int find_set(int x)
{
    if(DS[x] == x)
    {
        return x;
    }
    return (find_set(DS[x]));
}

bool Union(int x, int y)
{
    int a, b;
    a = find_set(x);
    b = find_set(y);
    
    if(a == b)
        return true;

    if(sz[a] < sz[b])
    {
        swap(a,b);
    }
    DS[b] = a;
    sz[a] += sz[b];

    return false;
}

int main()
{
    int n, x, y, f = 0;
    bool ret;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        if(!DS[x])
        {
            DS[x] = x;
            sz[x]++;
        }
        if(!DS[y])
        {
            DS[y] = y;
            sz[y]++;
        }
        
        ret = Union(x,y);
        if(ret)
        {
            f = 1;
        }
    }
    if(f == 1)
    {
        cout << "Cycle Present. " << endl;
        return 0;
    }
    cout << "Cycle Absent. " << endl ;
    return 0;
}