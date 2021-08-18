#include<iostream>
using namespace std;

int *brr;

int area(int lb, int ub, int key)
{
    int temp=0,i;
    for(i=lb+1; i<ub; i++)
    {
        temp+= (key-brr[i]);
    }
    return temp;
}


int main()
{
    int n,i,j,Water=0;
    cout<<"Enter number of blocks: ";
    cin>>n;
    brr= new int [n];
    cout<<"Enter height of block: ";
    for(i=0; i<n; i++)
        cin>>brr[i];
    int len=brr[0];
    int lb=0;
    for(i=1; i<n; i++)
    {
        if(len<=brr[i]  ||  i==n-1)
        {
            if(i<n-1)
                Water+=area(lb,i,len);
            else
            {
                if(len>brr[i])
                    Water+=area(lb,i,brr[i]);
                else
                    Water+=area(lb,i,len);
            }
            len=brr[i];
            lb=i;
        }
    }

    cout<<"Water = "<<Water<<endl;
    return 0;
}
