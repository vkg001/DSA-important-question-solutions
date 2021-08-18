#include<iostream>

using namespace std;

class Queue
{
    int num;
    Queue *next;

public:

    Queue *front;
    Queue *end;

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

    void enqueue(int n)
    {
        Queue *nn= new Queue(n);
        if(front==NULL)
        {
            front=end=nn;
        }
        else
        {
            end->next=nn;
            end=nn;
        }
    }


    void Display()
    {
        if(front==NULL)
        {
            cout<<"Queue is Underflow."<<endl;
            return;
        }
        else
        {
            Queue *temp=front;
            cout<<"Front-> ";
            while(temp->next!=NULL)
            {
                cout<<temp->num<<"-> ";
                temp=temp->next;
            }
            cout<<"End"<<endl;
        }
    }


    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue is Underflow."<<endl;
            return;
        }
        else
        {
            Queue *temp=front;
            cout<<temp->num<<" deleted."<<endl;
            front=front->next;
            free(temp);
            return;
        }
    }


    void peek()
    {
        if(front==NULL)
        {
            cout<<"Queue is Underflow."<<endl;
            return;
        }
        else
        {
            int c;
            cout<<front->num<<" is going to be deleted (1 to delete & 0 to leave)."<<endl;
            cin>>c;
            if(c==0)   dequeue();
        }
    }
};



int main()
{
    int n,i,x;
    Queue var;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(i=0;i<n;i++)
    {
        cin>>x;
        var.enqueue(x);
    }
    var.Display();
    var.peek();
    var.dequeue();
    var.peek();
    var.dequeue();
    var.peek();
    var.dequeue();
    var.peek();
    var.dequeue();
    var.Display();
    return 0;
}
