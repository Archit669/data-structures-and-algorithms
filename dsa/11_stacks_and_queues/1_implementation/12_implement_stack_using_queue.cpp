#include <bits/stdc++.h> 
using namespace std;

class Stack {
	queue<int> q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

     void push(int x) {
        q.push(x);
        for (int i = 0 ; i < q.size()-1 ; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};