#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, i, Max, Min;
    Max = Min = 0 ;
    vector<int> arr, brr;
    cin >> n;
    while(n--)
    {
        cin >> x;
        arr.push_back(x);
    }
    n = arr.size();

    sort(arr.begin(), arr.end(), greater<int>());

    for(i = n-1 ;  i >= n/2 ;  i--)
    {
        brr.push_back(arr[i]);
        arr.pop_back();
    }
    n /= 2;

    for(i = 0 ;   i < n ;   i++)
    {
        Max += (arr[i] - brr[i]);
        arr.push_back(brr[i]);
    }

    sort(arr.begin(), arr.end());
    
    n = arr.size();

    brr.clear();
    for(i = 0;   i < n/2;   i++)
    {
        brr.push_back(arr[i]);
        arr.erase(arr.begin()+i);
    }


    for(i = 0 ;   i < n/2 ;   i++)
    {
        Min += (arr[i] - brr[i]);
    }

    cout << Min << "  " << Max << endl ;

    return 0;
}