#include <bits/stdc++.h> 
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    // data members
    Node* qfront;
    Node* qrear;
public:
    Queue() {
        qfront = NULL;
        qrear = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (qfront == NULL) return true;
        return false;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (temp == NULL) return;
        
        if (qfront == NULL){
            qfront = temp;
            qrear = temp;
        }else{
            qrear->next = temp;
            qrear = qrear->next;
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = qfront->data;
        Node* temp = qfront;
        qfront = qfront->next;
        delete temp;
        return val;
    }

    int front() {
        if (qfront == NULL) return -1;
        return qfront->data;
    }
};