#include<iostream>
using namespace std;

void towerofhanoi(int n, char src, char destination, char helper)
{
    if(n==0)   return;
    towerofhanoi(n-1,src,helper,destination);
    cout<<src<<" to "<<destination<<endl;
    towerofhanoi(n-1,helper,destination,src);
}

int main()
{
    int n;
    cout<<"Enter number of blocks: ";
    cin>>n;
    towerofhanoi(n,'a','b','c');
    return 0;
}
