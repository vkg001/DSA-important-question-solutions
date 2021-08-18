#include<iostream>
using namespace std;

struct cards
{
    int num;
    char suite;
}selected;

struct cards card[53];

void shift(int x, int k)
{
    int i;
    for(i=x;i<k;i++)
        card[i]=card[i+1];
}

int main()
{
    int x,i,k=1;


    for(int j=0;j<4;j++)
    for(i=1;i<=13;i++)
    {
        card[k].num=i;
        switch(j)
        {
            case 0: card[k].suite='H'; break;
            case 1: card[k].suite='D'; break;
            case 2: card[k].suite='C'; break;
            case 3: card[k].suite='S'; break;
        }
        k++;
    }

    k=52;
    for(int j=0;j<4;j++)
    {
    for(i=0;i<13;i++)
    {
        x=(rand()%k)+1;
        selected=card[x];
        cout<<selected.num<<selected.suite<<"  ";
        shift(x,k);
        k--;
    }
    cout<<endl<<endl;
    }
    return 0;
}
