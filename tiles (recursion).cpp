#include<iostream>
using namespace std;
int board(int);
int main()
{
    int len;
    cout<<"Enter the length of board (len*2): ";
    cin>>len;
    cout<<board(len);
    return 0;
}

int board(int n)
{
    if(n==0)   return 0;
    else if(n==1)   return 1;
    else if(n==2)   return 2;
    int count;
    count=board(n-1)+board(n-2);
    return count;
}
