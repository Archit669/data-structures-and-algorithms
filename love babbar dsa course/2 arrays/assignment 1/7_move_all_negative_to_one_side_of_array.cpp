// this code will preserve the order of neg numbers but not the positive numbers

#include <iostream>
using namespace std;

void move_all_negative_to_right(int *arr,int n){
    int ptr1 = 0;

    while (arr[ptr1] < 0){
        ptr1++;
    }

    for (int i = ptr1 ; i < n ; i++){
        if (arr[i] < 0){
            swap(arr[ptr1],arr[i]);
            ptr1++;
        }
    }
}
 
int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    move_all_negative_to_right(arr,n);

    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}