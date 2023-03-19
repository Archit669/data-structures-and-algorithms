#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i = 1 ; i <= n/2; i++){
        int counter = 1+i*(i-1)/2;
        for (int j= 1 ; j<=i ; j++){
            if (j==1)
                cout << counter++;
            else
                cout << "*" << counter++;
        }cout << endl;
    }

    for (int i = n/2 ; i >= 1; i--){
        int counter = 1+i*(i-1)/2;
        for (int j= 1 ; j<=i ; j++){
            if (j==1)
                cout << counter++;
            else
                cout << "*" << counter++;
        }cout << endl;
    }
    return 0;
}