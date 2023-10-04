#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){

    int n, target;
    cin >> n >> target;


    vector<pair<int,int>> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx].first;
        arr[idx].second = idx+1;
    }


    sort(arr.begin(), arr.end());
    for (int idx = 0 ; idx < n ; idx++){
        for (int jdx = idx+1 ; jdx < n ; jdx++){
            int start = jdx+1;
            int end = n-1;

            while (start < end){
                int sum = arr[idx].first + arr[jdx].first + arr[start].first + arr[end].first;
                if (sum == target){
                    cout << arr[idx].second << " " << arr[jdx].second << " " << arr[start].second << " " << arr[end].second << endl; 
                    return 0;
                }else if(sum > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}