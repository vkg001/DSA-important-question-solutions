#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct elements
{
    int arrn;
    int ele;
    int idx;
};


struct sortbyele
{
    bool operator()(elements const &a, elements const &b)
    {
        return a.ele>b.ele;
    }
};


vector<int> sortKarrays(vector<int> *arr,int k)
{
    vector<int> result;
    priority_queue<elements, vector<elements>, sortbyele> minheap;
    int i,j,idx,ar,total=0;

    elements res;

    for(i=0; i<k; i++)
    {
        minheap.push({i,arr[i][0],0});
    }


    while(!minheap.empty())
    {
        res=minheap.top();
        ar=res.arrn;
        idx=res.idx;
        //cout<<arr[ar][idx]<<"  ";
        result.push_back(arr[ar][idx]);
        minheap.pop();
        if(idx+1<arr[ar].size())
            minheap.push({ar,arr[ar][idx+1],idx+1});
    }
    return result;
}


int main()
{
    int k,n,i,j,x;
    cout<<"Enter number of arrays: ";
    cin>>k;
    vector<int> arr[k];
    for(i=0; i<k; i++)
    {
        cout<<"Enter number of elements in array "<<i+1<<"\n";
        cin>>n;
        cout<<"Enter elements in sorted order\n";
        for(j=0; j<n; j++)
        {
            cin>>x;
            arr[i].push_back(x);
        }
    }

    vector<int> result = sortKarrays(arr,k);
    cout<<"Merged sorted array\n";
    for(auto var:result)
        cout<<var<<"  ";
    cout<<endl;
    return 0;
}
