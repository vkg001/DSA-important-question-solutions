#include<iostream>
#include<string>
using namespace std;

void rev(string str, int len)
{
    if(len<0)   return;
    cout<<str[len];
    rev(str,len-1);
    return;
}

int main()
{
    string str;
    cout<<"Enter any string ->\n";
    getline(cin,str);
    int len;
    len=str.length();
    rev(str,len-1);
    return 0;
}
