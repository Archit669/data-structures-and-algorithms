#include <iostream>
using namespace std;

// worst case complexity - O(n^2)
// best case complexity - O(n^2)

// used in small array
// used when time constraint

// stable(order maintained) or unstable(order not maintained)
// so it is unstable algorithm

// it is sort in place algorithm


void sort(int* arr, int n){
    for (int i = 0 ; i < n-1 ; i++){
        int min = i;
        for (int j = i+1 ; j < n ; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i] ,arr[min]);
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