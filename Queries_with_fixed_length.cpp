#include<bits/stdc++.h>

using namespace std;

int Calc(int arr[], int q, int st)
{
    int ret = INT_MIN;
    for(int i = st;  i < q+st;  i++)
        ret = max(ret, arr[i]);
    return ret;
}

int main()
{
    int n, q, j, i, mn, mx;
    vector<int> ans; 
    cin >> n >> q;
    int arr[n], queries[q];
    for(i=0;  i<n;  i++){
        cin >> arr[i];
    }
    for(i=0;  i<q;  i++){
        cin >> queries[i];
    }
    
    //Solution
    for(i=0;  i<q;  i++){
        j = 0;
        mx = INT_MIN;
        int mx2;
        mn = INT_MAX;
        while(j < queries[i]){
            mx = max(mx, arr[j]);
            j++;
        }
        mn = mx;
        for( ;  j < n-queries[i]+1;  j++){
            if(arr[j-queries[i]] == mx){
                mx = Calc(arr, queries[i], j-queries[i]+1);
            }else{
                mx = max(mx, arr[j]);
            }
            mn = min(mn, mx);
            cout << "M " << mx << endl;
            cout << "j " << j << endl;
        }
        ans.push_back(mn);
    }
    for(auto v: ans)
        cout << v << endl;
    return 0;
}