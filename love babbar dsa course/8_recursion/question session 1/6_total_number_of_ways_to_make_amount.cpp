#include <iostream>
using namespace std;

int totalWays(int* arr , int n ,int amt, int currentcoin = 0){
    if (amt == 0) return 1;
    if (amt < 0)  return 0;

    int ways = 0;

    for (int i = currentcoin; i < n ; i++){
        ways+=totalWays(arr,n,amt-arr[i],i);
    }

    return ways;
}
 
int main(){
    int n; int amt;
    cin >> n >> amt;

    int *arr = new int[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    cout << totalWays(arr,n,amt) << endl;
    return 0;
}