#include<bits/stdc++.h>

using namespace std;

int main()
{
    multiset<long long, greater<long long>> min_element;
    multiset<long long> max_element;
    long long n, x, h;
    cin >> n;
    while(n--)
    {
        char ch;
        cin >> ch;
        cin >> x;
        if(ch == 'a')
        {
            if(*min_element.begin() >= x)
                min_element.insert(x);
            else
                max_element.insert(x);

        }else{
            auto it = min_element.find(x);
            if(it == min_element.end()){
                it = max_element.find(x);
                if(it != max_element.end())
                    max_element.erase(it);
            }else{
                min_element.erase(it);
            }
        }

        // BALANCING
        if(min_element.size() > max_element.size() + 1){
            max_element.insert(*min_element.begin());
            min_element.erase(min_element.begin());
        }else if(max_element.size() > min_element.size() + 1){
            min_element.insert(*max_element.begin());
            max_element.erase(max_element.begin());
        }

        
        if(min_element.size() == 0   &&   max_element.size() == 0){
            cout << "Wrong!" << endl;
        }else{
            if(min_element.size() > max_element.size()){
                cout << *min_element.begin() << endl;
            }else if(min_element.size() < max_element.size()){
                cout << *max_element.begin() << endl;
            }else{
                cout << (long double)(*min_element.begin() + *max_element.begin())/2 << endl;
            }
        }
    }
    return 0;
}