#include<iostream>
#include<string>
using namespace std;

void substrings(string str, int len)
{
    int i,j;
    for(i=0;i<(1<<len);i++)
    {
        cout<<"{";
        for(j=0;j<len;j++)
            if(i&(1<<j))   cout<<str[j]<<" ";
        cout<<"}"<<endl;
    }
}

int main()
{
    string str;
    cout<<"Enter any string: ";
    getline(cin,str);
    int len=str.length();
    substrings(str,len);
    return 0;
}
