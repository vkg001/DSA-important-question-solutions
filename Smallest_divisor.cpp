#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, thrshld, sum, f;
    cin >> n;
    vector<int> arr;
    for(i=0;  i<n;  i++)
    {
        cin >> j;
        arr.push_back(j);
    }
    cin >> thrshld;
    for(i=1;  ;  i++)
    {
        sum = j = 0;
        f = 1;
        while(sum <= thrshld   &&   j < n)
        {
            if(arr[j]%i != 0)
            {
                sum += (arr[j]/i)  + 1;
            }
            else{
                sum += (arr[j]/i);
            }
            if(sum > thrshld)
            {
                f = 0;
                break;
            }
            j++;
        }
        if(f == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}