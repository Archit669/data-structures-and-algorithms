#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> input,output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int val = peek();
        if (output.empty()) return -1;
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()){
            while (!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        
        if (output.empty()) return -1;
        
        return output.top();
    }
    
    bool empty() {
        if (output.empty() && input.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */