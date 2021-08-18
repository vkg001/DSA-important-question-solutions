#include<stack>
#include<iostream>
#include<climits>

using namespace std;

stack<int> stk;
int mn = INT_MAX;

int Min_Element()
{

}

int main()
{
    int q, x, y;
    cin >> q;
    while(q--)
    {
        cin >> x;
        switch(x)
        {
            case 1: cin >> y;
                    if(y < mn){
                        stk.push(y*2 - mn);
                        mn = y;
                    }else{
                        stk.push(y);
                    }
                    break;


            case 2: if(stk.top() < mn){
                        mn = mn*2 - stk.top();
                        stk.pop();
                    }else{
                        stk.pop();
                    }
                    break;

            case 3: if(stk.top() < mn){
                        cout << mn << endl;
                    }else{
                        cout << stk.top() << endl;
                    }
                    break;

            case 4: cout << mn << endl;
                    break;
        }
    }
    return 0;
}