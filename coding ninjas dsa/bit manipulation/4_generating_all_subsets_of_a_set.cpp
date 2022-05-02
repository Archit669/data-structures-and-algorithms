#include <bits/stdc++.h>
using namespace std;

// approach 1
// time complexity - O(2^n)
// space complexity - O(1)
void print_subsets(int* arr, int n){
    for (int i = 0 ; i < pow(2,n); i++){
        for (int j= 0 ;j < n ; j++){
            if(i&(1<<j)){
                cout << arr[j] << " "; 
            }
        }cout << endl;
    }
}
 
int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    print_subsets(arr,n);
    return 0;
}