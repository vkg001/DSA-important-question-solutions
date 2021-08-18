#include<iostream>
#include<limits.h>
using namespace std;


class Queue
{
    int num;
    Queue *next, *front, *end;
public:
    Queue()
    {
        front=NULL;
        end=NULL;
    }
    Queue(int n)
    {
        num=n;
        next=NULL;
    }
    void Insert(int x)
    {
        Queue *nn=new Queue(x);
        if(front==NULL)
        {
            front=end=nn;
            return;
        }
        else
        {
            end->next=nn;
            end=nn;
            return;
        }
    }
    void Display();
    int Peek(int n, int i);

}var;


void Queue::Display()
{
    if(front==NULL)
    {
        cout<<"Queue is underflow."<<endl;
        return;
    }
    Queue *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<temp->num<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int Queue::Peek(int n, int i)
{
    if(front==NULL)
    {
        return -2;
    }
    else
    {
        Queue *temp;
        temp=front;
        int j=0;
        while(temp!=NULL  &&  j<i)
        {
            //cout<<temp->num<<"   ";
            temp=temp->next;
            j++;
        }
        //cout<<endl;
        while(j<n)
        {
            //cout<<temp->num<<"  ";
            temp=temp->next;
            j++;
        }
        return(temp->num);
    }
}


void WindowMaximum(int k, int n)
{
    int i,j,crr;
    for(i=0; i<n-(k-1); i++)
    {
        crr=INT_MIN;
        for(j=0; j<k; j++)
        {
            if(var.Peek(i+j,i)>crr)   crr=var.Peek(i+j,i);
        }
        cout<<crr<<"   ";
    }
}

int main()
{
    int *brr,n,i,x;
    cout<<"Enter number of elements: ";
    cin>>n;
    brr= new int [n];
    for(i=0; i<n; i++)
    {
        cin>>x;
        var.Insert(x);
    }
    var.Display();
    cout<<"Enter size of window: ";
    cin>>x;
    WindowMaximum(x,n);
    return 0;
}
