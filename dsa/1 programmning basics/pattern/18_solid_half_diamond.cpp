#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i = 1 ; i <= n/2 ; i++){
        for (int j = 1 ; j<=i ; j++ ){
            cout << "* ";
        }cout << endl;
    }
    for (int i = n/2-1 ; i >= 1 ; i--){
        for (int j = 1 ; j<=i ; j++ ){
            cout << "* ";
        }cout << endl;
    }cout << endl;
    return 0;
}