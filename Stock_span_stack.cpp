#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    int n, x, i;
    stack<pair<int, int>> stk;
    vector<int> arr, ans;
    cin >> n;
    for(i=0;  i<n;  i++){
        cin >> x;
        arr.push_back(x);
    }
    stk.push({arr[0], 1});
    ans.push_back(1);
    for(i=1;  i<n;  i++)
    {
        x = 0;
        while(stk.top().first <= arr[i]  &&  !stk.empty())
        {
            x += stk.top().second;
            stk.pop();
        }
        stk.push({arr[i], 1+x});
        ans.push_back(1+x);
    }
    for(auto v: ans){
        cout << v << " ";
    }
    return 0;
}