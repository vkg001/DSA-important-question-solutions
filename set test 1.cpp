#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{
    int n,ar[10];
    set<int> arr;
    unordered_set<int> us;
    cout<<"Enter elements\n";
    for(int i=0; i<10; i++)
    {
        cin>>ar[i];
        arr.insert(ar[i]);
        us.insert(ar[i]);
    }
    cout<<"Elements of array\n";
    for(int i=0; i<10; i++)
    {
        cout<<ar[i]<<"   ";
    }
    cout<<endl<<"Elements of set\n";
    set<int>::iterator it;
    it=arr.begin();
    while(it!=arr.end())
    {
        cout<<*it<<"   ";
        it++;
    }
    cout<<"\nElements in unordered set\n";
    unordered_set<int>::iterator it2;
    it2=us.begin();
    while(it2!=us.end())
    {
        cout<<*it2<<"   ";
        it2++;
    }
    cout<<endl;
    return 0;
}
