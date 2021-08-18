#include<bits/stdc++.h>

using namespace std;

double Generator(double num, double n)
{
    double res = 1;
    while(n--)
    {
        res *= num;
    }
    return res;
}

double NthRoot(double num, int n)
{
    double low, high, mid, accuracy = 1e-7 ;
    low = 1 ;       high = num ;
    while(high - low > accuracy)
    {
        mid = (low + high)/2 ;
        if(Generator(mid, n) > num)
        {
            high = mid ;
        }
        else
        {
            low = mid ;
        }
    }
    return high;
}
int main()
{
    double num, n;
    cin >> num >> n;
    
    num = NthRoot(num, n);

    cout << n <<"th root of given number is " << num << endl ; 

    return 0;
}