#include <bits/stdc++.h> 
using namespace std;

class Queue {
    // data members of queue
    queue<int> q;

public:
    Queue() {
        // Implement the Constructor
    }
    
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return q.empty();
    }

    void enqueue(int data) {
        q.push(data);
    }

    int dequeue() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int front() {
        if (q.empty()) return -1;
        return q.front();
    }
};