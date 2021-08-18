#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //Declaration of pair
    pair<int,char> xyz;
    //It can have only 2 members as its name suggests 'pair'


    //accessing of elements
    xyz.first=9;
    xyz.second='h';

    //Pair can also be used with vector
    vector<pair<int,int>> x;
    return 0;
}
