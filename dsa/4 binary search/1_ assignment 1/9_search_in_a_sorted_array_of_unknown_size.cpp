#include <iostream>
using namespace std;

int binary_search(int* arr ,int low, int high , int key){
    while (low <= high){
        int mid = low + (high - low)/2;
        if (arr[mid] == key){
            return mid;
        }else if (arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}

int search(int* arr, int key){
    int low = 0;
    int high = 1;
    int val = arr[high];

    while (val < key){
        low = high;
        high <<= 1;
        val = arr[high];
    }

    int ans = binary_search(arr ,low , high ,key);
    return ans;
}
 
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    int key;
    cin >> key;

    for (int i = 0 ; i < n ; i++) cin >> arr[i];

    if (search(arr,key) != -1){
        cout << "element found" << endl;
    }else{
        cout << "element not found" << endl;
    }
    return 0;
}