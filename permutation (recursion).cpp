#include<iostream>
#include<string>
using namespace std;

void permutation(string str, string ans)
{
    char ch;
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    int i=0;
    while(i<str.length())
    {
        ch=str[i];
        string ros=str.substr(0,i)+str.substr(i+1);
        i++;
        permutation(ros,ans+ch);
    }
}

int main()
{
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    permutation(str,"");
    return 0;
}
