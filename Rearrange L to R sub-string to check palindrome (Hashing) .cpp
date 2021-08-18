#include<iostream>
#include<string>

using namespace std;

const int N = 1e6 + 10;
int hsh[26][N];

int main()
{
    int q, L, R, i;
    string str;
    cin >> str ;

    for(i=0; i<str.length(); i++)
    {
        hsh[str[i]-'a'][i] ++ ;
    }

    for(i=0; i<26; i++)
    {
        for(int j=1; j<str.length(); j++)
        {
            hsh[i][j] += hsh[i][j-1];
        }
    }


    /*

    for(i=0; i<26; i++)
    {
        char c;
        c = i+'a';
        cout<<c<<"     ";
        for(int j=0; j<str.length(); j++)
        {
            cout<<hsh[i][j]<<"  ";
        }
        cout<<endl;
    }

    */

    /*      TIME COMPLEXITY


    Max length of string = 1e5

    for 2nd loop 26*1e5

    for 3rd loop 26*1e5

    Total iterations = 2*(26*1e5)

    Result -> Executable in 1 sec.

    */


    cin >> q ;

    while(q--)
    {
        cin >> L >> R ;
        L--;    R--;
        int c=0, f=1;
        for(i=0; i<26; i++)
        {
            int temp = hsh[i][R] - hsh[i][L-1];
            if(temp % 2 == 1)
                c++;
            if(c>1)
            {
                cout<<"No\n";
                f=0;
                break;
            }
        }
        if(f==1)   cout<<"Yes\n";
    }


    return 0;
}
