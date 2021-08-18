#include<iostream>
using namespace std;
char stack[200];
int top=-1;
////////////////////////////////////////////////////////

char pop();
void push(int n);

////////////////////////////////////////////////////////
bool push(char n)
{
    if(top<200)
    {
        top++;
        stack[top]=n;
    }
    else
    {
        cout<<"Stack is full.";
    }
}


char pop()
{
    if(top<=200  &&  top>-1)
    {
        top--;
        return stack[top+1];
    }
    return 0;
}


int main()
{
    int n,c=1;
    string str;
    cout<<"Enter parenthesis ->\n";
    getline(cin,str);
    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i]==')'  ||  str[i]==']'  ||  str[i]=='}')
        switch(str[i])
        {
        case '}':
            if(pop()=='{')  c=1;
            else   c=0;
            break;
        case ')':
            if(pop()=='(')  c=1;
            else   c=0;
            break;
        case ']':
            if(pop()=='[')  c=1;
            else   c=0;
            break;
        }
        else
        {
           n=push(str[i]);
           c=1;
        }
        if(c==0)
        {
            cout<<"Not balanced parenthesis.";
            return 0;
        }
    }
    cout<<"Balanced Parenthesis.";
    return 0;
}

