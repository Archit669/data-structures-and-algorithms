#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

    for (int i = 1 ; i <= n/2 ; i++){
        for (int j = 1 ; j <= n-i ; j++){
            cout << " ";
        }
        for (int j = 1; j <=i ; j++){
            if (j==1 || j==i)
                cout << '*' << " ";
            else  
                cout << "  "; 
        }cout << endl;
    }
    for (int i = n/2 ; i >= 1 ; i--){
        for (int j = 1 ; j <= n-i ; j++){
            cout << " ";
        }
        for (int j = 1; j <=i ; j++){
            if (j==1 || j==i)
                cout << '*' << " ";
            else  
                cout << "  "; 
        }cout << endl;
    }
    return 0;
}