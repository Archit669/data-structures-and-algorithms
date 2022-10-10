#include <bits/stdc++.h> 
using namespace std;

class Queue {
    // data members
    int size;
    int* arr;
    int qfront;
    int rear;
    
public:
    Queue() {
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (qfront == rear) return true;
        return false;
    }

    void enqueue(int data) {
        if (rear == size) return;
        arr[rear] = data; 
        rear++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        
        if (qfront == rear) {
             qfront = 0;
             rear  = 0;
        }
        
        return val;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[qfront];
    }
};