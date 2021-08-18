#include<iostream>
#include<string>
using namespace std;


char *Stack;
int top=-1;

char pop()
{
    if(top==-1)
        return -1;
    top--;
    return(Stack[top+1]);
}


void push(char x)
{
    top++;
    Stack[top]=x;
}


int main()
{
    char x,y;
    int i=1,f=0;
    string str;
    cout<<"Enter expression with redundant brackets ->\n";
    getline(cin,str);
    f=str.length();
    Stack= new char [f];
    f=0;
    x=str[0];
    while(x)
    {
        switch(x)
        {
        case ')':
            y=pop();
            if(y!='(')
            {
                while(y!='(')
                {
                    y=pop();
                }
            }
            else
                f++;
            break;
        case '}':
            y=pop();
            if(y!='{')
            {
                while(y!='{')
                    y=pop();
            }
            else
                f++;
            break;
        case ']':
            y=pop();
            if(y!='[')
            {
                while(y!='[')
                    y=pop();
            }
            else
                f++;
            break;
        default:
            if(x=='+'  ||  x=='-'  ||  x=='*'  ||  x=='/'  ||  x=='%'  ||  x=='('   ||  x=='['  ||  x=='{')
                push(x);
        }
        x=str[i];
        i++;
    }
    cout<<"Redundant bracket(s) in above expression = "<<f;
    return 0;
}
