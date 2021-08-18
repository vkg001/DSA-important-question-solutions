#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void Clock(int h, int m, int s)
{
    while(true)
    {
        Sleep(1000);
        s++;
        if(s > 59)
        {
            s = 0;
            m++;
        }
        if(m > 59)
        {
            m = 0;
            h++;
        }
        if(h > 23)
        {
            h = 0;
        }
        system("cls");
        cout << "\n\n\n\t\t\t\t\t\t CLOCK\n\n" << endl ;
        if(h < 10)
            cout << "\t\t\t\t\t 0" << h << " h  : ";
        else
            cout << "\t\t\t\t\t " << h <<" h  :  " ;
        if(m < 10)
            cout <<"0" << m <<" m  :  " ;
        else
            cout << m << " m  :  " ;
        if(s < 10)
            cout <<"0" << s << " s" << endl ;
        else
         cout << s <<" s " << endl;
    }
}

int main()
{
    int h, m, s;
    cin >> h >> m >> s ;
    Clock(h, m, s);
    return 0;
}
