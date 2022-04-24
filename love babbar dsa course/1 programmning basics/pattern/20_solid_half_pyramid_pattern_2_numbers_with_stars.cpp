#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i =1 ; i<=n/2 ;i++){
        for (int j =1 ; j<= i ; j++){
            if (j==1){
                cout << i;
            }else{
                cout << "*" << i;
            }
        }cout << endl;
    }
    for (int i =n/2 ; i>=1 ;i--){
        for (int j =1 ; j<= i ; j++){
            if (j==1){
                cout << i;
            }else{
                cout << "*" << i;
            }
        }cout << endl;
    }cout << endl;
    return 0;
}