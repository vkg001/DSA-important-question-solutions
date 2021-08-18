#include<iostream>
#include<queue>
using namespace std;



int main()
{
    int n,i,k,temp=0,c=0;
    priority_queue<int, vector<int> > heap;
    cout<<"Enter number of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements\n";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        heap.push(arr[i]);
    }
    cout<<"Enter sum of sub-sequence\n";
    cin>>k;
    while(temp<k  &&  (!heap.empty())   &&  k>0)
    {
        temp+=heap.top();
        c++;
        heap.pop();
    }
    if(heap.empty())
    {
        cout<<"No sub-sequence is possible!\n";
        return 0;
    }
    cout<<"Minimum elements in sub-sequence should be "<<c<<endl;
    return 0;
}
