#include<iostream>
#include<string>
using namespace std;

void chkpi(string str, int index, int len)
{
    if(len==index)   return;
    if(str[index]=='p'  &&  str[index+1]=='i')
    {
        cout<<"3.14";
        chkpi(str,index+2,len);
    }
    else
    {
        cout<<str[index];
        chkpi(str,index+1,len);
    }

}

int main()
{
    string str;
    cout<<"Enter any string (containing 'pi') ->\n";
    getline(cin,str);
    int len=str.length();
    chkpi(str,0,len);
    return 0;
}
