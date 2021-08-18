#include<stack>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    int n, x, i, j;
    vector<int> arr, ans;
    stack<int> stk;
    cin >> n;
    for(i=0;  i<n;  i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    for(i=0;  i<n;  i++)
    {
        if(stk.empty())
            ans.push_back(-1);
        else
        {
            if(arr[i] < stk.top())
            {
                ans.push_back(stk.top());
            }
            else
            {
                while(stk.top() <= arr[i]   &&   !stk.empty())
                {
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(stk.top());
                }
            }
        }
        stk.push(arr[i]);
    }
    for(auto v: ans){
        cout << v << " ";
    }
    return 0;
}