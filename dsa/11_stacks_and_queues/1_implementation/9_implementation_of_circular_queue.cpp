#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    // data members
    int size;
    int* arr;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        // overflow condition
        if (front== (rear+1)%size){
            return false;
        }else{
            // insert in queue
            if (rear == -1){
                arr[++rear] = value;
                ++front;
            }else{
                rear = (rear + 1)%size;
                arr[rear] = value;
            }
            return true;
        }
    }
    
    bool deQueue() {
        // underflow condition
        if (front == -1) return false;
        else{
            // dequeue
            if (front == rear){
                front = -1;
                rear = -1;
                return true;
            }
            front = (front + 1)%size;
            return true;
        }
    }
    
    int Front() {
        if (front == -1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if (rear == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if (front== -1) return true;
        return false;
    }
    
    bool isFull() {
        if (front== (rear+1)%size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
