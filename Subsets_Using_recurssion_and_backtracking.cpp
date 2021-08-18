#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> result;

void GenerateSubSets(vector<int> &elements, vector<int> &v1, int i)
{
    if(elements.size() == i)
    {
        result.push_back(v1);
        return;
    }
    
    v1.push_back(elements[i]);
    GenerateSubSets(elements, v1, i+1);
    v1.pop_back();
    GenerateSubSets(elements, v1, i+1);
}



int main()
{
    vector<int> elements;
    int x;

    do
    {
        cin >> x;
        if(x!=0)
            elements.push_back(x);
    } while (x != 0);
    
    vector<int> Subsets;

    GenerateSubSets(elements, Subsets, 0);

    for(auto vect: result)
    {
        for(auto var: vect)
        {
            cout << var <<"  ";
        }
        cout << endl;
    }

    return 0;
}