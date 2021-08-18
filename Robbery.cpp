#include<iostream>
using namespace std;
struct node
{
    float weight;
    float price;
    float avg;
    int index;
};

void quicksort(struct node* details, int lb, int ub);
int partition(struct node* details, int lb, int ub);
void swap(struct node, struct node);

int main()
{
    int i,n,curr=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    struct node details[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter weight for item "<<i+1<<" : ";
        cin>>details[i].weight;
        cout<<"Enter price for item "<<i+1<<" : ";
        cin>>details[i].price;
        details[i].avg=(details[i].price/details[i].weight);
        details[i].index=i+1;
    }
    int w;
    cout<<"Enter Max. weight that robber can hold: ";
    cin>>w;
    quicksort(details,0,n-1);
    int j=n-1;
    for(i=n-1;i>=0;i--)
    {
       // cout<<details[i].index<<"  ";
        curr+=details[i].weight;
        if(curr<=w)
            cout<<details[i].index<<"  ";
        else if(curr>w)   curr-=details[j--].weight;
    }
    return 0;
}


void quicksort(struct node* details, int lb, int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(details,lb,ub);
        quicksort(details,lb,loc-1);
        quicksort(details,loc+1,ub);
    }
}

int partition(struct node* details, int lb, int ub)
{
    float pivot,temp;
    pivot=details[lb].avg;
    int start,end;
    start=lb+1;
    end=ub;
    while(start<end)
    {
        while(pivot>=details[start].avg)   start++;
        while(pivot<details[end].avg)   end--;
        if(start<end)
             swap(details[start],details[end]);
    }
    swap(details[end],details[lb]);
    return end;
}


void swap(struct node details,struct node details2)
{
    struct node temp;
    temp.weight=details.weight;
    temp.price=details.price;
    temp.avg=details.avg;
    temp.index=details.index;

    details.weight=details2.weight;
    details.price=details2.price;
    details.avg=details2.avg;
    details.index=details2.index;

    details2.weight=temp.weight;
    details2.price=temp.price;
    details2.avg=temp.avg;
    details2.index=temp.index;
}
