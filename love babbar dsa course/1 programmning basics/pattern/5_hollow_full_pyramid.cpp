#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n--1i ; j++){
            cout << " ";
        }
        for (int k = 0 ; k <= i ; k++){
            if (i == n-1 || k == 0 || k == i )
                cout << "* ";
            else
                cout << "  ";
        }cout << endl;
    }
    return 0;
}