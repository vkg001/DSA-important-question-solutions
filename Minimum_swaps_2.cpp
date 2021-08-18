#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int minimumSwaps(vector<int> arr)
{
    int minSwaps = 0, i, temp, j, f ;
    for(i = arr.size()-1;  i >= 0;  i--)
    {
        while(arr[i] != i+1)
        {
            minSwaps++;
            j = arr[i];
            temp = arr[j-1];
            arr[i] = temp;
            arr[j-1] = j;
        }
    }
    
    return minSwaps;
}

int main()
{
    int n ;
    vector<int> arr;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << minimumSwaps(arr) << endl ;
    return 0;
}
