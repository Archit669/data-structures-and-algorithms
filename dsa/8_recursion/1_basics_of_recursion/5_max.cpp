#include <iostream>
using namespace std;

int max(int* arr, int n, int ans = INT_MIN){
    if (n==0) return ans;
    ans = max(ans,*arr);
    return max(arr+1,n-1,ans);

}
 
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0 ; i <  n ; i++){
        cin >> arr[i];
    }

    cout << max(arr,n) << endl;
    return 0;
}