#include<iostream>
#include<conio.h>
using namespace std;


class DoubleQueue
{
    int num;
    DoubleQueue *next, *front, *end;
public:
    DoubleQueue()
    {
        front=NULL;
        end=NULL;
    }
    DoubleQueue(int n)
    {
        num=n;
        next=NULL;
    }
    void InsertFront(int x)
    {
        DoubleQueue *nn=new DoubleQueue(x);
        if(front==NULL)
        {
            front=end=nn;
            return;
        }
        else
        {
            nn->next=front;
            front=nn;
            return;
        }
    }

    void InsertEnd(int x)
    {
        DoubleQueue *nn=new DoubleQueue(x);
        end->next=nn;
        end=nn;
        return;
    }

    void DeleteFront()
    {
        if(front==NULL)
        {
            cout<<"Queue is underflow."<<endl;
        }
        else
        {
            DoubleQueue *temp;
            temp=front;
            if(front==end)
                front=end=NULL;
            else
                front=front->next;
            cout<<temp->num<<" deleted."<<endl;
            free(temp);
            return;
        }
    }

    void DeleteEnd();
    void Display();

};


void DoubleQueue::DeleteEnd()
{
    if(front==NULL)
    {
        cout<<"Queue is underflow."<<endl;
    }
    else
    {
        DoubleQueue *temp;
        temp=front;
        if(front==end)
            front=end=NULL;
        else
        {
            while(temp->next!=end)
                temp=temp->next;
        }
        temp->next=NULL;
        cout<<end->num<<" deleted."<<endl;
        free(end);
        end=temp;
        return;
    }
}


void DoubleQueue::Display()
{
    if(front==NULL)
    {
        cout<<"Queue is underflow."<<endl;
        return;
    }
    DoubleQueue *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<temp->num<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}



int main()
{
    DoubleQueue x;
    cout<<"//////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    cout<<"             MAIN FUNCTION IS STATIC TRY TO EDIT SOURCE CODE"<<endl<<endl<<endl;
    cout<<"//////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    x.InsertFront(5);
    x.InsertFront(9);
    x.InsertFront(3);
    x.InsertFront(8);
    x.InsertFront(4);
    x.Display();
    x.InsertEnd(45);
    x.InsertEnd(34);
    x.InsertEnd(87);
    x.InsertEnd(23);
    x.Display();
    x.DeleteEnd();
    x.DeleteEnd();
    x.DeleteEnd();
    x.DeleteEnd();
    x.Display();
    x.DeleteFront();
    x.DeleteFront();
    x.DeleteFront();
    x.DeleteFront();
    x.DeleteFront();
    x.DeleteFront();
    x.Display();
    getch();
    return 0;
}
