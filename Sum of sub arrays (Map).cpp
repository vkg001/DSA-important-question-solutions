#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vect;
    int x, n, c = 0 , l = 0;
    map<int, int> res;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        vect.push_back(x);
        l += x;
        res[l]++;
    }

    for(auto &var: res)
    {
        int h = var.second;
        c += (h*(h-1)/2);

        if(var.first == 0)
            c +=var.second;
    }

    cout<<c;

    return 0;
}
