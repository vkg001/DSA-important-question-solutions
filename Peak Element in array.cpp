#include<iostream>
#include<vector>
using namespace std;


vector<int> Peak(int *arr, int n)
{
    vector<int> res;
    if(arr[0]>arr[1])
        res.push_back(arr[0]);
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i+1]  &&  arr[i]>arr[i-1])
        {
            res.push_back(arr[i]);
        }
    }
    if(arr[n-1]>arr[n-2])
    {
        res.push_back(arr[n-1]);
    }
    return res;
}



int main()
{
    vector<int> res;
    int arr[]={10,20,15,2,23,90,67};
    res=Peak(arr,7);
    cout<<"Peak elements are\n";
    for(auto var:res)
        cout<<var<<"  ";
    return 0;
}
