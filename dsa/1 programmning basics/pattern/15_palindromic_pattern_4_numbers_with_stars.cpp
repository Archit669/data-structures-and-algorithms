#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i = 1 ;  i<=n ; i++){
        for (int j = 1 ; j <= 8-i+1 ; j++){
            cout <<"*";
        }
        for (int j = 1; j <=i ; j++){
            if (j==1){
                cout << i;
            }else{
                cout << "*" << i;
            }
        }
        for (int j = 1 ; j <= 8-i+1 ; j++){
            cout <<"*";
        }cout << endl;
    }
    return 0;
}