#include <iostream>
using namespace std;

void reverse(int*arr , int n){
    int start = 0;
    int end = n-1;

    while (start <= end){
        swap(arr[start],arr[end]);
        start++; end--;
    }
}
 
int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    reverse(arr,n);

    cout << "array after reversal is: " << endl;
    for (int i =0 ; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}