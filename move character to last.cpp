#include<iostream>
#include<string>
using namespace std;

char moveLast(string str, char Last, int len)
{
    if(len<=0)   return Last;
    if(str[0]==Last)   cout<<moveLast(str.substr(1),Last,len-1);
    else
    {
        cout<<str[0];
        moveLast(str.substr(1),Last,len-1);
    }
    return Last;
}

int main()
{
    string str;
    cout<<"Enter any string : ";
    getline(cin,str);
    char c;
    cout<<"Enter character to move at last position from string: ";
    cin>>c;
    int len=str.length();
    moveLast(str,c,len);
    return 0;
}
