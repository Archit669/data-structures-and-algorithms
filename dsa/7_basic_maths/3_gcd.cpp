#include <iostream>
using namespace std;

// // approach1 - using % operator
// inline int gcd(int a , int b){
//     if (b==0) return a;
//     return gcd(b, a%b);
// }
 
// approach2 -using - operator
// inline int abs(int num){
//     if (num < 0) return -num;
//     return num;
// }
// inline int min(int a, int b){
//     if (a>b) return b;
//     return a;
// }
// inline int gcd(int a , int b){
//     if (b==0) return a;
//     if (a==0) return b;
//     return gcd(abs(a-b),min(a,b));
// }

// approach -3 iteratively
int gcd(int a , int b){
    if (a==0) return b;
    if (b==0) return a;
    while (a!=b){
        if (a>b) a= a-b;
        else b = b-a;
    }
    return a;
}

int main(){ 
    cout << gcd(72,24) << endl;
    return 0;
}