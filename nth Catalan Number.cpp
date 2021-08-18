#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    int n,i,j,k,s,t;
    cout<<"Enter the number of term of Catalan Series: ";
    cin>>n;
    for(i=2;i<n;i++)
    {
        s=0;
        for(j=0,k=i-1;j<i && k>=0;j++,k--)
        {
            s+=arr[j]*arr[k];
        }
        arr.push_back(s);
    }
    for(i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<"\nCatalan number "<<n<<" is "<<arr[n-1]<<endl;
    return 0;
}
