#include<bits/stdc++.h>

using namespace std;

int main()
{
    multiset<long long, greater<long long>> max_element;
    multiset<long long> min_element; 
    long long n, i, x, a, b;
    char ch;
    cin >> n;
    while(n--)
    {
        cin >> ch;
        cin >> x;
        if(ch == 'a')
        {
            if(max_element.size() > min_element.size())
            {
                min_element.insert(x);
            }
            else
            {
                max_element.insert(x);
            }

            if(min_element.size() == max_element.size())
            {
                cout << (*min_element.begin() + *max_element.begin())/2 << endl;
            }
            else
            {
                if(min_element.size() > max_element.size())
                    cout << (*min_element.begin()) << endl;
                else
                    cout << (*max_element.begin()) << endl;
            }
        }
        else
        {
            auto it = max_element.find(x);
            if(it == max_element.end())
            {
                it = min_element.find(x);
                if(it != min_element.end())
                    min_element.erase(it);
            }
            else
                max_element.erase(it);
            
            if(max_element.size() == 0   &&   min_element.size() == 0)
                cout << "Wrong!" << endl;
            else
            {
                if(max_element.size() > min_element.size())
                    cout << (*max_element.begin()) << endl;
                else if(min_element.size() == max_element.size())
                    cout << (*max_element.begin() + *min_element.begin())/2 << endl;
                else
                    cout << (*min_element.begin()) << endl;
            }
        }
    }
    return 0;
}