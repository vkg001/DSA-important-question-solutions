#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool MyComp(pair<int,int>p1, pair<int, int>p2)
{
    return(p1.first<p2.first);
}


int main()
{
    int n,x;
    vector<pair<int, int>> element;
    cout<<"Enter number of elements: ";
    cin>>n;
    int brr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        brr[i]=x;
        element.push_back(make_pair(x,i));
        /*
        OR

        pair<int,int> p;
        p.first=x;
        p.second=i;
        element.push_back(p);

        */
    }

    sort(element.begin(),element.end(),MyComp);
    //'MyComp' will tell sort() that according to which value elements should be sorted

    for(int i=0;i<element.size();i++)
    {
        brr[element[i].second]=i;
    }
    cout<<"Reduced array is ->\n";
    for(int i=0;i<n;i++)
        cout<<brr[i]<<"  ";
    return 0;
}
