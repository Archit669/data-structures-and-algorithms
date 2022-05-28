#include <iostream>
using namespace std;

int factorial(int n){
    // base case
    if (n<=0) return 1;
    // recursive case
    return n*factorial(n-1);
}
 
int main(){
    // take number from user
    int n;
    cin >> n;
    // calculate factorial of that number
    cout << factorial(n) << endl;
    return 0;
}