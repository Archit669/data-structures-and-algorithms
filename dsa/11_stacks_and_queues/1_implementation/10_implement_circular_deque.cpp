#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    // data members
    int front;
    int rear;
    int* arr;
    int size;
public:
    // constructor
    MyCircularDeque(int k) {
        this->front = -1;
        this->rear = -1;
        this->arr = new int[k];
        this->size = k;
    }
    
    // insert at front
    bool insertFront(int value) {
        // check overflow condition
        if (isFull()){
            return 0;
        }
        // check whether is queue is empty or not
        if (front == -1){
            arr[++front] = value;
            ++rear;
        }else{
            front = (front -1 +size)%size;
            arr[front] = value;
        }
        
        return 1;
    }
    
    // insert at rear
    bool insertLast(int value) {
        // check overflow condition
        if (isFull()){
            return 0;
        }
        // check whether is queue is empty or not
        if (front == -1){
            arr[++front] = value;
            ++rear;
        }else{
            rear = (rear+1)%size;
            arr[rear] = value;
        }
        
        return 1; 
    }
    
    // delete at front
    bool deleteFront() {
        // check underflow condition
        if (front == -1) return 0;
        // if queue has only one element
        if (front == rear){
            front = rear = -1;
        }else{
             front = (front+1)%size;
        }
        
        return 1;
    }
    
    // delete at rear
    bool deleteLast() {
        // check underflow condition
        if (front == -1) return 0;
        // if queue has only one element
        if (front == rear){
            front = rear = -1;
        }else{
            rear = (rear - 1 +size)%size; 
        }
        return 1;   
    }
    
   // get front of queue 
    int getFront() {
        return front == -1 ? -1 : arr[front];
    }
    
    // get rear of queue
    int getRear() {
        return rear == -1 ? -1 : arr[rear];
    }
    
    // check whether queue is empty or not
    bool isEmpty() {
        return front == -1;
    }
    
    // check whether queue is full or not
    bool isFull() {
        if (front == (rear + 1)%size ) return 1;
        if ((front -1 + size)%size == rear) return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */