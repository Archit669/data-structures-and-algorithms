// worst case complexity - O(n^2)
// best case complexity - O(n)

// this algo is stable
// this algo is in-place

#include <iostream>
using namespace std;

void sort(int* arr, int n){
    for (int i = 1 ; i < n ; i++){
        for (int j = i ; j>0 ; j--){
            if (arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
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