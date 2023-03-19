// worst case - O(n^2)
// best case  - O(n)


// it is stable algorithm (order is maintained)
// it is in-place algo (no extra space)

#include <iostream>
using namespace std;

void sort(int* arr, int n){
    for (int i = 0 ; i < n-1 ; i++){
        int flag = 1;
        for (int j = 0 ; j < n-1-i ; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 0;
            }
        }
        if(flag){
            break;
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

    sort(arr,n);

    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}