#include<iostream>
#include<vector>
#include<math.h>
using namespace std;



bool isPalindrome(long x)
{
    cout<<x<<endl;
    long temp=x;
    long num=0;
    while(temp)
    {
        num=num*10+(temp%10);
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
    if(isPalindrome(num))
        return 0;
    for(long i=k; i<n; i++)
    {
        //cout<<num<<endl;
        num=num-(arr[i-k] *((long)pow(10,k-1)));

        cout<<num<<endl;
        num=num*10+(arr[i]);
        cout<<num<<endl;
        if(isPalindrome(num))
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
        cout<<"Palindromic sub-array not found.\n";
        return 0;
    }
    cout<<"Palindromic sub-array of size k found from index "<<ret<<" to "<<ret+k<<"\n";
    for(i=ret;i<ret+k;i++)
        cout<<str[i];
    cout<<endl;
    return 0;
}
