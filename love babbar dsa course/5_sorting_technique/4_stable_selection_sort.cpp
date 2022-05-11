// worst case complexity - O(n^2)
// best case complexity - O(n)

// this algo is stable
// this algo is in-place

#include <iostream>
using namespace std;

void sort(int* arr, int n){
    for (int i = 0 ; i < n-1 ; i++){
        int min = i;
        for (int j = i+1 ; j < n ; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        while (i < min){
            arr[min]= arr[min-1];
            min--;
        }
        arr[i] = temp;
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