#include<bits/stdc++.h>

using namespace std;


void Chaos(vector<int> q)
{
    int TBs, CBs, i, j, Smallest = INT_MAX ;
    vector<int>  Min;
    for(i = (q.size()-1);   i >= 0;   i--)
    {
        if(Smallest > q[i])
        {
            Smallest = q[i] ;
        }
        Min.push_back(Smallest) ;
    }

    TBs = CBs = 0;
    for(i = (q.size()-1);   i >= 0;   i--)
    {
        CBs = 0 ;
        for(j = i+1;   j < q.size();   j++)
        {
            if(Min[j] > q[i])
            {
                break;
            }
            if(q[i] > q[j])
            {
                CBs++;
                TBs++;
            }
            if(CBs > 2)
            {
                cout << "Too chaotic \n" ;
                return ;
            }
        }
    }
    cout << TBs << endl ;
}


int main()
{
    vector<int> q;
    int testcases, elements ;
    cin >> testcases ;
    while(testcases--)
    {
        cin >> elements ;
        while(elements--)
        {
            int x;
            cin >> x ;
            q.push_back(x);
        }
        Chaos(q);
        q.clear();
    }
    return 0;
}