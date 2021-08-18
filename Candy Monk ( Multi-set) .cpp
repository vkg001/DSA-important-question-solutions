#include<bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int>  st ;
    int  i, n, k, x ;
    cin >> n >> k ;
    while(n--)
    {
        cin >> x ;
        st.insert(x);
    }
    int temp,  Max = 0 ;
    while(k--)
    {
        auto it = st.rbegin();
        temp = (*it);
        st.erase(st.find(temp));
        Max += temp;
        st.insert(temp/2);
    }
    cout<<Max<<endl;
    return 0;
}
