#include <bits/stdc++.h> 
class TwoStack {

public:
    // data members
    int* arr;
    int size;
    int top;
    int top1;
    int top2;
    int size1;
    int size2;
    
    // constructor
    TwoStack(int s) {
        this->arr = new int[s];
        this->size = s;
        this->top1 = -1;
        this->top2 = -1;
        this->size1 = 0;
        this->size2 = 0;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (size1 + size2 == size) return;
        else{
            top1++;
            arr[top1] = num;
            size1++;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (size1 + size2 == size) return;
        if (top2 == -1) top2 = size-1;
        else top2--;
        size2++;
        arr[top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 != -1){
            int val = arr[top1];
            top1--;
            size1--;
            return val;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 == -1) return -1;
        int val = arr[top2];
        if (top2 == size-1) top2 = -1;
        else top2++;
        size2--;
        return val;
    }
};
