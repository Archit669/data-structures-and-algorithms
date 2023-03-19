#include <iostream>
using namespace std;

int solve(int*arr,int n){
    int start = 0;
    int end = n-1;
    while (start <=end){
        if (arr[start] == arr[end]){
            start++;
            end--;
        }else{
            return false;
        }
    }
    return true;
}
 
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0  ; i< n ; i++){
        cin >> arr[i];
    }

    int ans = solve(arr,n);
    cout << ans << endl;
    return 0;
}