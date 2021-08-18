#include<iostream>
using namespace std;
const int N=10e4;
int main()
{
    long n,brr[N]={0},temp,fac,i;
    do
    {
    cout<<"Enter number( 0 to exit ): ";
    cin>>n;
    //for(i=2;i<=n;i++)   cout<<brr[i];
    for(i=2;i<=n;i++)
    {
        if(brr[i]==0)
        for(int j=i*i;j<=n;j+=i)
            if(j%i==0)   brr[j]=1;
    }
    temp=n;
    i=2;
    while(temp!=1  &&  i<=n)
    {
            if(brr[i]==0)
                if(temp%i==0)
                {
                    temp/=i;
                    cout<<i<<"  ";
                    i--;
                }
            i++;
    }
    cout<<"\n\n\n";
    }while(n!=0);
    return 0;
}
