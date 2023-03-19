#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;

   cout << "*" << endl;
    for (int i = 1 ; i <= (n-2)/2+1 ; i++){
        cout << "* ";
        int j;
        for (j = 1 ; j <= (2*i-1)/2+1 ; j++){
                cout << j << " ";
        }
        j = j-2;
        for (j ; j >=1 ; j--){
            cout << j << " ";
        }

        cout << "*" << endl;
    }   

    for (int i = (n-2)/2 ; i >= 1  ; i--){
        cout << "* ";
        int j;
        for (j = 1 ; j <= (2*i-1)/2+1 ; j++){
                cout << j << " ";
        }
        j = j-2;
        for (j ; j >=1 ; j--){
            cout << j << " ";
        }

        cout << "*" << endl;
    }   
         
   cout << "*" << endl;

    return 0;
}