#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int main()
{
    int brr[N],i,n;
    cout<<"Enter size of array (Max. 100): ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    sort(brr,brr+n);
    for(i=0;i<n;i++)
        cout<<brr[i]<<"  ";
    return 0;
}
