#include<iostream>
#include<string>
using namespace std;

void SubString(string str, int n);
bool chk(char ch, char*, int);

int main()
{
    string str;
    cout<<"Enter string ->\n";
    getline(cin,str);
    int x=str.length();
    SubString(str,x);
    return 0;
}


void SubString(string str, int n)
{
    int len,k,i;
    char ch[n];
    len=0;
    k=0;
    ch[k]=str[0];
    k++ ;
    for(i=1; i<n; i++)
    {
        if(chk(str[i],ch,k)==1)
        {
            ch[k]=str[i];
            k++;
        }
        else
        {
            if(len<k)   len=k;
            k=0;
            ch[k]=str[i];
            k++;
        }
        if(len<k)  len=k;
    }
    cout<<"Max. length of sub-string is "<<len<<endl;
}


bool chk(char ch, char* str, int n)
{
    for(int i=0;i<n;i++)
    {
        if(ch==str[i])
             return false;
    }
    return true;
}
