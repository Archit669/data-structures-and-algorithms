#include <iostream>
using namespace std;


void swap_alternate(long long int* arr ,long long int n){
    int i = 0;
    while (i+1 < n){
        swap(arr[i],arr[i+1]);
        i+=2;
    }
}
 
int main(){
    long long int n;
    cin >> n;
    long long int *arr = new long long int[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    swap_alternate(arr,n);

    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}