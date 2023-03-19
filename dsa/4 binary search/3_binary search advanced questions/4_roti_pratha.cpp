#include <bits/stdc++.h>
using namespace std;

bool isPossible(int* arr, int n , int prathas ,int mid){
    int cntParathas = 0;
    for (int i = 0 ; i < n ; i++){
        int time = arr[i];
        int j = 2;
        while (time <= mid){
            cntParathas++;
            time+= arr[i]*j;
            j++;
        }
    }

    if (cntParathas >=prathas){
        return true;
    }

    return false;
}


int solve(int*arr ,int n , int prathas){
    int start = 0;
    int end = 0;
    int ans = -1;
    for (int i = 1 ; i <= prathas ; i++){
        end+=i*arr[0];
    }

    while (start <= end){
        int mid = start + (end - start)/2;
        if (isPossible(arr,n,prathas,mid)){
            ans = mid;
            end = mid -1;
        }else{
            start = mid + 1;
        }
    }

    return ans;

}
 
int main(){
    vector<int> res;
    int t;
    cin >> t;

    while (t--){
        int prathas;
        cin >> prathas;
        int n;
        cin >> n;

        int* arr = new int[n];
        for (int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        res.push_back(solve(arr,n,prathas));
        delete [] arr;
    }

    for (int i = 0 ; i < res.size() ; i++){
        cout << res[i] << endl;
    }

    return 0;
}