#include<iostream>
#include<string>
using namespace std;

void remDup(string str, int index)
{
    if(index>=str.length())   return;
    cout<<str[index];
    int i=index+1;
    while(i<=str.length())
    {
        if(str[i]==str[index])
        {
            str.erase(i,1);
            i--;
        }

        i++;
    }
    remDup(str,index+1);
}

int main()
{
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    remDup(str,0);
    return 0;
}
