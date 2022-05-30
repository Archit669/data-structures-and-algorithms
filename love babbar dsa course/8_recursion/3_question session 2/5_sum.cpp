#include <iostream>
using namespace std;

// function to calculate sum of array.
int sum(int* arr, int n){
    if (n==0) return 0;
    return arr[0] + sum(arr+1, n-1);
}

// main function
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << sum(arr,n) << endl;
    return 0;
}