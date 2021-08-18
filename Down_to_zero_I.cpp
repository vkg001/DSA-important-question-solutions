#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, SQRT, count;
    map<int, bool> visited;
    queue<pair<int, int>> sols;
    pair<int, int>  temp;
    bool found = false;
    cin >> n;
    sols.push({n,0});
    while(!sols.empty())
    {
        temp = sols.front();
        sols.pop();
        SQRT = sqrt(temp.first);
        while(SQRT > 0)
        {
            i = temp.first - (SQRT*SQRT);
            if(i == 0)
            {
                found = true;
                count = temp.second + 1;
                break;
            }
            if(!visited[i])
            {
                visited[i] = true;
                sols.push({i, temp.second + 1});
            }
            SQRT--;
        }
        if(found)
        {
            break;
        }
    }
    cout << count << endl;
    return 0;
}