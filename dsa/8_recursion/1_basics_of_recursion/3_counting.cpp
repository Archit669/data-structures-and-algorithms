#include <iostream>
using namespace std;

void counting(int n){
    // base case
    if (n == 1){
        cout << 1 << " ";
        return;
    }
    // recursive case
    counting(n-1);
    // print current value of n.
    cout << n << " ";   
}
 
int main(){
    // take no of terms from user
    int n;
    cin >> n;
    // print counting
    counting(n);
    cout << endl;
    return 0;
}