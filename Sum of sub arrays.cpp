#include<iostream>
using namespace std;
int main()
{
    int sum,n,brr[50],i,j;
    cout<<"Enter number of element: ";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>brr[i];
    sum=0;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            sum+=brr[j];
    cout<<sum<<endl;
    return 0;
}
