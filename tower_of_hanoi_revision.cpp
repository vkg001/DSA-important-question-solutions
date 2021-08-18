#include<iostream>

using namespace std;

int step = 1;

void tower(int n, string &src, string &dest, string &help)
{
    if(n<1)
        return;
    tower(n-1, src, help, dest);
    cout << step++ << ".   |   " << src << " -> " << dest << endl ;
    tower(n-1, help, dest, src);
}

int main()
{
    int n, i = 0, x;
    cin >> n;
    cout << "Step |   Move" << endl;
    string s = "source";
    string h = "helper";
    string d = "destination" ;
    tower(n, s, d, h);
    return 0;
}