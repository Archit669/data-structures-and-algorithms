#include <iostream>
using namespace std;

/*
// bruteforce approach
// time complexity - O(n)
// space complexity - O(n) -> due to recursion
int power(int x,int n){
    if (n == 0) return 1;
    return x*power(x,n-1);
}
*/


/*
// bruteforce approach
// time complexity - O(n)
// space complexity - O(1)
int power(int x,int n){
    int res = 1;
     while(n>0){
         res*=x;
         n--;
     }
     return res;
}
*/

// bruteforce approach
// time complexity - O(n)
// space complexity - O(1)
int power(int x,int n){
   
}



 
int main(){
    int x;  int n;
    cin >> x >> n;
    cout << power(x,n) << endl;
    return 0;
}