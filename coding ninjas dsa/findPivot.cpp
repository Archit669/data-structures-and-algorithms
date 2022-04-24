#include <iostream>
using namespace std;

int findPivot(int* arr , int n){
    int start = 0;
    int end = n-1;

    while (start <= end){
        int mid = start + (end - start)/2;
        if (arr[mid] < arr[mid+1] && arr[mid] < arr[mid -1]){
            return mid;
        }else if(arr[mid] > arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return -1;
}
 
int main(){
    int n;
    int* arr = new int[n];

    for (int i = 0 ; i < n ;  i++){
        cin >> arr[i];
    }

    cout << findPivot(arr,n) << endl;
    return 0;
}