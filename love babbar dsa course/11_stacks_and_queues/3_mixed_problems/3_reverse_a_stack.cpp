#include <bits/stdc++.h>
#include <stack>
using namespace std;

// approach - 1

void pushAtBottom(stack<int> &s , int x){
    if (s.empty() ){
        s.push(x);
        return;
    }else{
        int val = s.top();
        s.pop();
        pushAtBottom(s,x);
        s.push(val);
    }
    
}

void reverseStack(stack<int> &stack) {
    if (stack.empty()) return;
    int val = stack.top();
    stack.pop();
    reverseStack(stack);
    pushAtBottom(stack,val);
}