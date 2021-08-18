#include<iostream>
#include<math.h>
using namespace std;

int binaryTodecimal(char*,int);

int main()
{
    char num[500],ch;
    int Size=0,i=0,res;
    cout<<"Enter number in binary: ";
    cin>>num;
    while(num[i++]!='\0')
    {
        ch=num[i-1]-'0';
        if(ch>1)
        {
            cout<<"Number is not in binary...."<<endl;
            goto label;
        }

        Size++;
    }

    cout<<"Length of given number is "<<Size<<endl<<num;
    res=binaryTodecimal(num,Size);
    cout<<" is equivalent to "<<res<<" in decimal."<<endl;
    label:
    return 0;
}


int binaryTodecimal(char* num, int len)
{
    int x,i,j,temp=0,ret;
    for(i=len-1,ret=0;i>=0;i--,ret++)
    {
        j=num[i]-'0';
        if(j==1)
        {
            x=pow(2,ret);
            temp+=x;
        }
        else
            continue;
    }
    return temp;
}
