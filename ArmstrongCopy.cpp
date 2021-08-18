#include<iostream>
#include<vector>
using namespace std;


long POW(long num, long n)
{
    int ret=1;
    for(long i=0;i<n;i++)
    {
        ret*=num;
    }
    return ret;
}


bool isPerfect(long x)
{
    //cout<<x<<endl;
    long temp=x,digit=0;
    long num=0;
    while(temp)
    {
        digit++;
        temp/=10;
    }
    temp=x;
    while(temp)
    {
        num+=((long)POW(temp%10,digit));
        temp/=10;
    }
    if(num==x)
    {
        return true;
    }
    return false;
}


long MakeNum(vector<long> arr, long k)
{
    long n=arr.size();
    long num=0;
    for(long i=0; i<k; i++)
    {
        num=num*10+arr[i];
    }
    if(isPerfect(num))
        return 0;
    for(long i=k; i<n; i++)
    {
        //cout<<num<<endl;
        //cout<<(arr[i-k] *((long)POW(10,k-1)))<<endl;
        num=num-(arr[i-k] *((long)POW(10,k-1)));

        //cout<<num<<endl;
        num=num*10+arr[i];
        //cout<<num<<endl;
        if(isPerfect(num))
            return i-k+1;
    }
    return -1;
}



int main()
{
    long i,n,k,ret;
    vector<long> str;
    cout<<"Enter number of elements \n";
    cin>>n;
    cout<<"Enter elements\n";
    for(i=0;i<n;i++)
    {
        long x;
        cin>>x;
        str.push_back(x);
    }
    cout<<"Enter size of subarray\n";
    cin>>k;
    ret=MakeNum(str,k);
    if(ret==-1)
    {
        cout<<"Perfect number sub-array not found.\n";
        return 0;
    }
    cout<<"Perfect number sub-array of size k found from index "<<ret-1<<" to "<<ret+k-1<<"\n";
    for(i=ret;i<ret+k;i++)
        cout<<str[i];
    cout<<endl;
    return 0;
}