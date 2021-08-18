#include<iostream>
using namespace std;
void subsets(int* brr, int size)
{
    int i,j;
    for(i=0;i< (1<<size);i++)
    {
        cout<<"{";
        for(j=0;j<size;j++)
        {
            if( (1<<j) & i)   cout<<brr[j]<<" ";
        }
        cout<<"}";
        cout<<endl;
    }
}

int main()
{
    int brr[100],n,i;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
        cin>>brr[i];
    subsets(brr, n);
    return 0;
}
