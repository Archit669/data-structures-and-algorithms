#include <bits/stdc++.h> 
using namespace std;

void pushAtRightPlace(stack<int> &stack, int val){
    if (stack.empty()){
        stack.push(val);
        return;
    }
    
    else if (stack.top() < val) {
        stack.push(val);
        return;
    }
    
    else{
        int element = stack.top();
        stack.pop();
        pushAtRightPlace(stack,val);
        stack.push(element);
        
    }
}
void sortStack(stack<int> &stack)
{
	if (stack.empty()) return;
    
    int val = stack.top();
    stack.pop();
    sortStack(stack);
    pushAtRightPlace(stack,val);
}