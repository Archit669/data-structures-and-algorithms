#include <iostream>
using namespace std;

int search(int* arr, int n,int target,int index = 0){
    if (n<=0){
        index = -1;
        return index;
    }
    if (target == *arr){
        return index;
    }
    return search(arr+1,n-1,target,index+1);
}
 
int main(){
    int n;
    cin >> n;
    int target;
    cin >> target;
    int* arr = new int[n];
    for (int i = 0 ; i <  n ; i++){
        cin >> arr[i];
    }

    cout << search(arr,n,target) << endl;
    return 0;
}