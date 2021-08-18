#include<iostream>
using namespace std;

int paths(int start, int end)
{
    if(start==end)   return 1;
    if(start>end)   return 0;
    int i,count=0;
    for(i=1;i<7;i++)
    count+=paths(start+i,end);
    return count;
}

int main()
{
    int start,end;
    cout<<"Enter start point: ";
    cin>>start;
    cout<<"Enter end point: ";
    cin>>end;
    cout<<paths(start,end);
    return 0;
}
