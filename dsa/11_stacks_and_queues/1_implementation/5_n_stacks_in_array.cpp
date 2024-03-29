#include <bits/stdc++.h>
using namespace std;

/*
// using 2-d array
class NStack
{
public:
    int** arr;
    int* top;
    int N;
    int S;
    int count = 0;
    
    NStack(int N, int S)
    {
        this->N = N;
        this->S = S;
        
        arr = new int*[N];
        for (int i = 0 ; i < N ; i++){
            arr[i] = new int[S];
        }
        
        
        top = new int[N];
        for (int i = 0 ; i < N ; i++){
            top[i] = -1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (count == S) return false;
        m = m-1;
        if (m< 0 || m >= N || top[m] == S ) return false;
        top[m]++;
        arr[m][top[m]] = x;
        count++;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        m = m-1;
        if (m< 0 || m >= N || top[m] == -1 ) return -1;
        int val = arr[m][top[m]];
        top[m]--;
        count--;
        return val;
    }
};

*/


// optimized approach
class NStack
{
public:
    // data members
    int* arr;
    int* top;
    int* next;
    int freespot;
    
    // constructor
    NStack(int N, int S)
    {
        arr = new int[S];
        next = new int[S];
        top = new int[N];
        freespot = 0;
        
        // initialize all top to -1
        for (int i = 0 ; i < N; i++){
            top[i] = -1;
        }
        
        // initiaze all element of next
        for (int i = 0 ; i < S ; i++){
            next[i] = i+1;
        }
        
        // update last value of next
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot == -1) return 0;
        // find index
        int index = freespot;
        // push
        arr[index] = x;
        // update freespot
        freespot = next[index];
        // update next
        next[index] = top[m-1];
        // update top
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m-1] == -1) return -1;
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};


