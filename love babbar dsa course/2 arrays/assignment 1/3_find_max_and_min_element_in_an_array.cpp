#include <iostream>
using namespace std;

long long minElement(long long int* arr , long long int n){
    long long min = arr[0];
    for (int i = 1 ; i < n ; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}
long long maxElement(long long int* arr , long long int n){
    long long max = arr[0];
    for (int i = 1 ; i < n ; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}
 
int main(){
    long long int n;
    cin >> n;
    long long int *arr = new long long int[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    long long int min = minElement(arr,n);
    long long int max = maxElement(arr,n);

    cout << "minimum number is " << min << endl;
    cout << "maximum number is " << max << endl;

    return 0;
}