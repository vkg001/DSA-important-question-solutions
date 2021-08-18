#include<bits/stdc++.h>

using namespace std;

map<int, vector<string>>  result;

int idx;


bool createParanthesis(int All,  int Openings,  int Closing, vector<string> old)
{
    if(Openings + Closing == All   &&   Openings == All/2)
    {
        for(auto var: old)
            result[idx].push_back(var);
        idx++;
        return 1;
    }

    vector<string>  v1 = old;
    vector<string>  v2 = old;


    if(Openings > All/2   ||   Closing > Openings   ||   Closing > All/2)
    {
        return false;
    }


    if(Openings > Closing)
    {
        v1.push_back("(");
        createParanthesis(All, Openings+1, Closing, v1);

        v2.push_back(")");

        createParanthesis(All, Openings, Closing+1, v2);

        return true;
    }

    if(Openings < All/2)
    {
        v1.push_back("(");

        createParanthesis(All, Openings+1, Closing, v1);

        v2.push_back(")");

        createParanthesis(All, Openings, Closing+1, v2);

        return true;
    }

    return true;

}


int main()
{
    int n;

    cin >> n;

    vector<string>  v1;
    v1.push_back("(");

    createParanthesis(n*2, 1, 0, v1);
    for(auto vect: result)
    {
        for(auto var: vect.second)
        {
            cout<<var;
        }
        cout<<endl;
    }
    return 0;
}
