#include <iostream>
using namespace std;

// time complexity - O(n)
// space complexity - O(N)
// int powerOfTwo(int n){
//     if (n==0) return 1;
//     return 2*powerOfTwo(n-1);
// }



// time complexity - O(N)
// space complexity - O(N)

int powerOfTwo(int n){
    if (n==0) return 1;
    int cp = powerOfTwo(n/2);
    if (n&1){
        return cp*cp*2;
    }else{
        return cp*cp;
    }
}
 
int main(){
    int n;
    cout << "enter power: ";
    cin >> n;

    cout << "power of two is: " << powerOfTwo(n) << endl;
    return 0;
}