#include<iostream>
using namespace std;

int *brr;

int area(int lb, int ub, int key)
{
    int temp=0,i;
    for(i=lb+1;i<ub;i++)
        temp+= (key-brr[i]);
    return temp;
}


int main()
{
    int i,n,Water=0,lb=0,len;
    cout<<"Enter number of blocks: ";
    cin>>n;
    brr= new int [n];
    cout<<"Enter heights of blocks: ";
    for(i=0;i<n;i++)
        cin>>brr[i];
    len=brr[0];
    lb=0;
    for(i=1;i<n;i++)
    {
        if(len<=brr[i]  ||  i==n-1)
        {
            if(i<n-1)
            {
                Water+=area(lb,i,len);
                len=brr[i];
                lb=i;
            }
            else
            {
                if(len<=brr[i])
                {
                    Water+=area(lb,i,len);
                }
                else
                {
                    while(brr[i]<=brr[i-1])
                        i--;
                    Water+=area(lb,i,brr[i]);
                    break;
                }
            }
        }
    }
    cout<<"Water = "<<Water<<endl;
    return 0;
}
