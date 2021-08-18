#include <bits/stdc++.h>
using namespace std;

void SortStk(stack<int> &stk){
  stack<int> answer, helper;
  answer.push(stk.top());
  stk.pop();
  while(true){
    if(stk.empty()) break;
    int x = stk.top();
    stk.pop();
    if(x > answer.top()){
      helper.push(answer.top());
      answer.pop();
      answer.push(x);
    }else{
      answer.push(x);
    }
  }
  while(!helper.empty()){
    int x = helper.top();
    helper.pop();
    if(x > answer.top()){
      while(answer.top() < x){
        helper.push(answer.top());
        answer.pop();
      }
      answer.push(x);
    }else{
      answer.push(x);
    }
  }
  while(!answer.empty()){
    cout << answer.top() << endl;
    answer.pop();
  }
}

int main()
{
  stack<int> stk;
  int t, n, x;
  cin >> t;
  while(t--){
    cin >> n;
    while(n--){
      cin >> x;
      stk.push(x);
    }
    SortStk(stk);
  }
  
  return 0;
}