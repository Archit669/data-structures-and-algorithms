#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int counter = 3;
    for (int i = 1 ; i <= n/2+1 ; i++){
        for (int j =1 ; j<=i ;j++){
            cout << counter;
        }cout << endl;
        counter++;
    }
    counter = counter -2;
    for (int i = n/2 ; i >= 1 ; i--){
        for (int j =1 ; j<=i ;j++){
            cout << counter;
        }cout << endl;
        counter--;
    }

    return 0;
}