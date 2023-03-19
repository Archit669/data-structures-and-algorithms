#include <bits/stdc++.h>
using namespace std;

class heap{
    vector<int> arr;
    public:
        heap(){
            arr.push_back(-1);
        }

        void push(int data){
            arr.push_back(data);
            int n = arr.size()-1;
            while (n/2 > 0){
                if (arr[n] > arr[n/2]) swap(arr[n], arr[n/2]);
                else break;
                n /= 2;
            }
        }

        void print(){
            for (int i = 1 ; i < arr.size() ; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }
};

int main(){
    heap h;
    h.push(2);
    h.print();

    h.push(3);
    h.print();
    h.push(4);
    h.print();
   
    return 0;
}