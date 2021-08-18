#include<iostream>
#include<string>
using namespace std;

void substrings(string str, string ans)
{
    if(str.length()==0)
    {
        cout<<"{"<<ans<<"}"<<endl;
        return;
    }
    char ch=str[0];
    int x=ch;
    string cop=to_string(x);
    string ros=str.substr(1);
    substrings(ros,ans);
    substrings(ros,ans+ch);
    substrings(ros,ans+cop);
}

int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    substrings(str,"");
    return 0;
}
