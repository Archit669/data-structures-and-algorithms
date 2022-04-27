#include <iostream>
using namespace std;

/*

// approach 1

void sort_0_1_2(int* arr , int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0 ; i < n ; i++){
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }
    int counter = 0;
    for (int i = 0 ; i < count0 ; i++){
        arr[counter++] = 0;
    }
    for (int i = 0; i < count1 ; i++){
        arr[counter++] = 1;
    } 
    for (int i = 0; i < count2 ; i++){
        arr[counter++] = 2;
    } 
}

*/

// approach 2 (dutch national flag algo)
void sort_0_1_2(int *arr,int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++; mid++;
        }
        else if (arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

 
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0  ; i< n ; i++){
        cin >> arr[i];
    }

    sort_0_1_2(arr,n);

    for (int i = 0  ; i< n ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}