#include <iostream>
using namespace std;
 
int main(){
    // create 2-d array
    int m; int n;
    cin >> m >> n;
    int arr[m][n];

    // take input from array
    cout << "enter elements of matrix below : " << endl;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    // print matrix
    cout << "matrix is: " << endl;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;

    return 0;
}