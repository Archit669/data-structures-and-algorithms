#include <iostream>
using namespace std;

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