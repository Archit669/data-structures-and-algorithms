#include <iostream>
using namespace std;

int fibonacci(int n){
    // base case
    if (n <= 0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;


    // recursive case
    return (fibonacci(n-1) + fibonacci(n-2));
}
 
int main(){
    int n;
    cout << "enter no of terms: ";
    cin >> n;
    cout << "fibonacci series is: " << endl;
    for (int i = 1 ; i <=n ; i++){
        cout << fibonacci(i) << " "; 
    }cout << endl;
    return 0;
}