#include <iostream>
using namespace std;

// // approach 1
// bool isprime(int n){
//     if (n<=1) return false;
//     if (n==2) return true;
//     for (int i = 2 ; i < n ; i++){
//         if (n%i==0) return false;
//     }
//     return true;
// }


// // approach 2 (n/2 method)
// bool isprime(int n){
//     if (n<=1) return false;
//     if (n==2) return true;
//     for (int i = 2 ; i <= n/2 ; i++){
//         if (n%i == 0){
//             return false;
//         }
//     }
//     return true;
// }


// approach 3 (root n method)
// time complexity (root(n))
bool isprime(int n){
    if (n<=1) return false;
    if (n==2) return true;
    for (int i = 2 ; i*i <= n ; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

 
int main(){
    int n;
    cin >> n;

    cout << isprime(n) << endl;
    return 0;
}