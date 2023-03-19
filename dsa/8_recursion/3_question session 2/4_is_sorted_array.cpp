#include <iostream>
using namespace std;

// function to check given array is sorted or not
bool isSorted(int* arr , int n){
    if (n<0) return false;
    if (n==1 || n==0) return true;
    if (arr[0] > arr[1])  return false;
    return isSorted(arr+1, n-1);
}
 
// main function
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << isSorted(arr,n) << endl;
    return 0;
}