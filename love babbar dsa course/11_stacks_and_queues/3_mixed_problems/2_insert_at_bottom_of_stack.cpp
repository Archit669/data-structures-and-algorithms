#include <bits/stdc++.h>
using namespace std;
 
stack<int> pushAtBottom(stack<int>& s, int x) 
{
    if (s.empty()){
        s.push(x);
        return s;
    }
    
    int element = s.top();
    s.pop();
    pushAtBottom(s, x);
    s.push(element);
    
    return s;
}
