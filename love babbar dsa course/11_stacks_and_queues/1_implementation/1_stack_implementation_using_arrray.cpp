#include <bits/stdc++.h>
using namespace std;

class Stack{
    //data members
    int* arr;
    int size;
    int top;

    public:

        //constructor
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top = -1;
        }

        //destructor
        ~Stack(){
            delete[] arr;
        }

        // push
        bool push(int element){
            if (size- top > 1){
                top++;
                arr[top] = element;
                size++;
                return 1;
            }

            return 0;
        }


        // pop
        int pop(){
            if (top <= -1) return -1;
            int val = arr[top];
            top--;
            size--;
            return val;
        }


        // peek
        int peek(){
            if (top == -1) return -1;
            return arr[top];
        }


        // isEmpty
        bool isEmpty(){
            if (top <= -1) return true;
            return false;
        }

        // print stack
        void print(){
            int temp = top;
            if (top != -1){
                cout << arr[top] << " <---- top" << endl;
                temp--;
            }else{
                cout << "stack is empty" << endl;
            }

            while (temp > -1){
                cout << arr[temp] << endl;
                temp--;
            }
        }
};
 
int main(){
    
    return 0;
}