#include<iostream>
#include<string>
using namespace std;

char stack[200];
int top=-1;


void push(char n)
{
    int ch;
    if(top<200)
    {
    top++;
    stack[top]=n;
    }
    else
    {
        cout<<"Stack is full.\n";
    }
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
            cout<<stack[i];
        }
        cout<<endl;
    }
}



int main()
{
    string str;
    cout<<"Enter any sentence ->\n";
    getline(cin,str);
    int i,len=str.length();
    for(i=0;i<len;i++)
        push(str[i]);
    Display();
    return 0;
}
