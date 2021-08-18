#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int *arr, int n, int stud, int mid)
{
    int i,sum=0,s=1;
    for(i=0;i<n;i++)
    {
        if(arr[i]>mid)
            return false;
        if(sum+arr[i]>mid)
        {
            sum=arr[i];
            s++;
        if(s>stud)
            return false;
        }
        else
            sum+=arr[i];
    }
    return true;
}


int minPageAllocation(int *arr, int n, int stud)
{
    if(n<stud)
        return -1;
    int left,right,sum=0,mid,ans=INT_MAX;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    left=0;     right=sum;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(isPossible(arr,n,stud,mid))
        {
            ans=min(ans,mid);
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
}


int main()
{
    int *arr,stud,n,i;
    cout<<"Enter number of books : ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter number of pages\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter number of students: ";
    cin>>stud;
    i=minPageAllocation(arr,n,stud);
    cout<<"Minimum number of pages are "<<i<<endl;
    return 0;
}
