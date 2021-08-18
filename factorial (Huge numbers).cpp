#include<iostream>
#include<conio.h>
using namespace std;


int main()
{
    char ans[4001];
    long int carry=0,i,j=0,num,x,y,len;
    cout<<"Enter number (<=1460) to find factorial : ";
    cin>>num;
    x=num*(num-1);
    y=x;
    len=0;
    while(y)
    {
        ans[len]=(y%10)+'0';
        y/=10;
        len++;
    }
    num-=2;
    while(num>0)
    {
        i=0;
        while(i<len)
        {
            x=(ans[i]-'0')*num;
            x=x+carry;
            ans[i]=(x%10)+'0';
            carry=x/10;
            i++;
        }
        while(carry>0)
        {
            ans[i]=(carry%10)+'0';
            i++;
            len++;
            carry/=10;
        }
        num--;
    }
    i=len-1;
    while(i>=0)
    {
         cout<<ans[i];
         i--;
    }
    getch();
    return 0;
}
