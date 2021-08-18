#include<iostream>
using namespace std;
int stack[20],top=-1;

////////////////////////////////////////////////////////

void pop();
bool push(int n);
void Display();

////////////////////////////////////////////////////////


bool push(int n)
{
    int ch;
    if(top<20)
    {
        top++;
        stack[top]=n;
        cout<<"Top | "<<top+1<<endl<<endl;
        return true;
    }
    else
    {
        cout<<"Stack is full.\nDo you want to delete one element from last (1 for 'Yes' & 0 for 'No') ??\n";
        cin>>ch;
        if(ch==1)
        {
            pop();
            push(n);
        }
        else
            return false;
    }
}


void pop()
{
    if(top<=20  &&  top>-1)
    {
        cout<<"Element "<<stack[top]<<" is deleted."<<endl;
        top--;
    }
    else
        cout<<"Stack underflow."<<endl;
}


void Display()
{
    if(top==-1)
    {
        cout<<"Stack is Underflow."<<endl;
        return;
    }
    else
    {
        cout<<endl<<endl;
        for(int i=top; i>=0; i--)
        {
            if(i>0)
                cout<<stack[i]<<"\n^"<<endl;
            else
                cout<<stack[i]<<endl;
        }
    }
}


void ReverseStack(int temp,int ret)
{
    if(temp==0)
    {
        stack[ret]=stack[temp];
        return;
    }
    else
    {
        int x=stack[temp];
        ReverseStack(temp-1,ret+1);
        stack[ret]=x;
    }
}


int main()
{
    int n,x,ch;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements ->\n";
    for(int i=0 ; i<n ; i++)
    {
        cin>>x;
        ch=push(x);
        if(ch==0)
            break;
    }
    Display();
    ReverseStack(top,0);
    Display();
    return 0;
}
