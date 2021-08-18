#include<iostream>
using namespace std;
const int rows=4,cols=4;
int main()
{
    int brr[rows][cols],i,j,search,count=0;
    cout<<"Enter elements of your 2D array (4x4)->\n ";
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
             cin>>brr[i][j];
    cout<<"Enter element to search: ";
    cin>>search;
    i=0;
    j=cols-1;
    while(brr[i][j]!=search  &&  i<rows   &&   j>=0)
    {
        if(search<brr[i][j])
            j--;
        else
            i++;
        count++;
    }
    if(brr[i][j]==search)
        cout<<"Element found after checking "<<count<<" times at position ("<<i+1<<","<<j+1<<")";
    else
        cout<<"Element not found after checking "<<count<<" position(s).";
    return 0;
}
