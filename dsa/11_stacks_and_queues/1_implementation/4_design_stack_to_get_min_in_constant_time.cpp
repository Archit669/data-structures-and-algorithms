#include <bits/stdc++.h>
using namespace std;

// class SpecialStack {
//     // Define the data members.

//     /*----------------- Public Functions of SpecialStack -----------------*/
//     public:
//         stack<int> stk;
//         stack<int> aux;
        
//     void push(int data) {
//         stk.push(data);
//         if (aux.empty()) aux.push(data);
//         else aux.push(min(aux.top(),data));
//     }

//     int pop() {
//         if (stk.empty()) return -1;
//         int val = stk.top();
//         stk.pop();
//         aux.pop();
//         return val;
//     }

//     int top() {
//         if (stk.empty()) return -1;
//         return stk.top();
//     }

//     bool isEmpty() {
//         return stk.empty();
//     }

//     int getMin() {
//         if (aux.empty()) return -1;
//         return aux.top();
//     }  
// };


// approach -2

class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        stack<int> s;
        int mini;
  
    
    void push(int data) {
        if (s.empty()){
            s.push(data);
            mini = data;
        }
        
        else if (data < mini ){
            int val = 2*data - mini;
            s.push(val);
            mini = data;
        }
        
        else{
            s.push(data);
        }
    }

    int pop() {
        if (s.empty()) return -1;
        else if (s.top() < mini){
            int prevMin = mini;
            mini = 2*mini - s.top();
            s.pop();
            return prevMin;
        }else{
            int val = s.top();
            s.pop();
            return val;
        }
    }

    int top() {
        if (s.empty()) return -1;
        else if (s.top() < mini) return mini;
        else return s.top();
    }

    bool isEmpty() {
        if (s.empty()) return true;
        return false;
    }

    int getMin() {
        if (s.empty()) return -1;
        return mini;
    }  
};