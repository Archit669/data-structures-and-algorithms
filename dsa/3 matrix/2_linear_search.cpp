#include <iostream>
using namespace std;
 
int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int key = -1;
    int flag = 1;
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (arr[i][j]==key){
                cout << "element found" << endl;
                flag = 0;
            }
        }
    }
    
    if (flag){
        cout << "element not found" << endl;
    }
    return 0;
}