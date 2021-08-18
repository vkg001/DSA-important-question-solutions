#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;
int table[N][N];

int MCM(vector<int> &arr, int idx, int k)
{
    if(idx >= k)
        return 0;
    if(table[idx][k] != -1)
        return table[idx][k];
    table[idx][k] = INT_MAX;
    for(int i=idx;  i<k;  i++)
    {
        table[idx][k] = min(table[idx][k], MCM(arr, idx, i) + MCM(arr, i+1, k) + (arr[i] * arr[idx-1] * arr[k]));

    }
    return table[idx][k];
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    while(n--)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    memset(table, -1, sizeof(table));
    cout << MCM(arr, 1, arr.size()-1) << endl;
    return 0;
}