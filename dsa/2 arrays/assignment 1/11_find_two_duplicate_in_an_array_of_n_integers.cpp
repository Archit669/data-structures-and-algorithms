#include <iostream>
using namespace std;

int findDuplicate(int*arr , int n){
    int res = 0;
    for (int i = 0 ; i <n ; i++){
        res^= arr[i];
    }
    for (int i = 1 ; i < n ; i++){
        res^= i;
    }
    return res;
}
 
int main(){
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int res = findDuplicate(arr,n);
    cout << res << endl;
    return 0;
}