#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


pair<set<int>,int> CheckElements(int* arr, int n, int k)
{
    int i,j,left,right,mid,t,x;
    pair<set<int>,int> s,ret;
    left=0;
    right=arr[n-1];
    mid=(left+right)/2;
    ret.second=0;
    while(left<right)
    {
        int pos=arr[0];
        for(i=1; i<n; i++)
        {
            if(arr[i]-pos>=mid  &&  s.first.size()<=k)
            {
                s.first.insert(pos);
                s.first.insert(arr[i]);
                pos=arr[i];
            }
        }
        s.second=mid;
        if(s.first.size()<k)
        {
            s.first.clear();
            right=mid;
            mid=(left+right)/2;

        }
        else
        {
            //s.second=mid;
            if(ret.second<s.second)
            {
            ret.first.clear();
              ret.second=s.second;
            for(auto var:s.first)
                ret.first.insert(var);
            }
            s.first.clear();
            left=mid+1;
            mid=(left+right)/2;

        }
    }
    return ret;
}


int main()
{
    int *arr,n,k,i=0;
    cout<<"Enter size of array: ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter elements\n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"Enter number of elements you want in your set: ";
    cin>>k;
    pair<set<int>,int> s=CheckElements(arr,n,k);
    cout<<"\n\nMaximum difference in "<<k<<" elements will be "<<s.second<<endl<<"And elements are\n";
    cout<<"{  ";
    for(auto ele:s.first)
    {
        cout<<ele<<"  ";
        i++;
        if(i==k)
            break;
    }

    cout<<"}"<<endl;
    return 0;
}
