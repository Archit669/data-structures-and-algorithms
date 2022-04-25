#include <iostream>
using namespace std;

int linearSearch(int*arr , int n , int key){
    for(int i = 0 ; i < n ; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}
 
int main(){
    int n;
    cout << "enter no of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "enter element of array below: " << endl;
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int key;
    cout << "enter key: "; 
    cin >> key;

    int index = linearSearch(arr,n,key);
    cout << key << " is present at index "<< index << endl;
    return 0;
}