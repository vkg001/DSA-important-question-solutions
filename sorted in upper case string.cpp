#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;
int main()
{
    string str,str1;
    cout<<"Enter string: ";
    getline(cin,str);
    sort(str.begin(),str.end());
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<str;
    return 0;
}
