#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, cows, stalls[N];

bool canPlaceCow(int dist)
{
    int count_cw = cows;
    int i = 0, pos = -1;
    while(i < n)
    {
        if(stalls[i]-pos >= dist  ||  pos == -1)
        {
            pos = stalls[i];
            count_cw--;
        }
        i++;
        if(count_cw == 0)
            return true;
    }
    return count_cw == 0;
}

int main()
{
    cin >> n;
    cin >> cows;
    int i = n;
    while(i--)
        cin >> stalls[i];
    sort(stalls, stalls+n);
    int lo = 0,  hi = N, mid;
    while(hi - lo > 1)
    {
        mid = (lo + hi)/2;
        if(canPlaceCow(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    canPlaceCow(hi) ? cout << hi : cout << lo ;
    return 0;
}