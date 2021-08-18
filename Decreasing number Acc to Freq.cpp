#include<bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> vect;
    int x;
    do
    {
        cin >> x;
        if(x==0)
            break;

        vect.push_back(x);


    }while(x!=0);

    int k, temp;

    cin >> k;

    temp = vect[0];

    map<int, int>  res;

    for(auto var: vect)
    {
        if(temp != var)
        {
            k--;
            temp = var;
        }
        if(k == 0)
            break;

        res[temp] ++ ;

    }



    set<pair<int, int>, greater<pair<int, int>> >  finalRes;

    for(auto &var: res)
    {
        finalRes.insert(make_pair(var.second, var.first));
    }


    for(auto &var: finalRes)
    {
        cout << var.second  << "   " <<var.first <<  endl;
    }


    return  0;
}
