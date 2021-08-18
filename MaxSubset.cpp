#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
int table[N];

int main()
{
    int n, x, i, ans = 0;
    vector<int> arr;
    cin >> n;
    while(n--)
    {
        cin >> x;
        arr.push_back(x);
    }
    //table[-1] = 0;
    table[0] = table[1] = max(0, arr[0]);
    for(i = 1;  i < arr.size();  i++)
    {
        table[i] = max(table[i-2], max(arr[i] + table[i-2], table[i-1]));
    }
    n = arr.size();
    ans = max(table[n-1], table[n-2]);
    cout << ans << endl;
    return 0;
}