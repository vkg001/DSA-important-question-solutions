#include<iostream>
using namespace std;
int robbery(int weight[], int price[], int maxw, int n)
{
    if(n==0  ||  maxw==0)   return 0;
    int x,y;
    if(maxw<weight[n-1])
    {
        return robbery(weight,price,maxw,n-1);
    }
    x=robbery(weight,price,maxw-(weight[n-1]),n-1)+price[n-1];
    y=robbery(weight,price,maxw,n-1);
    if(x>y)   return x;
    return y;
}

int main()
{
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    int weight[n],price[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter weight for item "<<i<<" : ";
        cin>>weight[i];
        cout<<"Enter price for item "<<i<<" : ";
        cin>>price[i];
    }
    int maxw;
    cout<<"Enter max weight: ";
    cin>>maxw;
    cout<<"Max. price of items that can be stolen is "<<robbery(weight,price,maxw,n);
    return 0;
}
