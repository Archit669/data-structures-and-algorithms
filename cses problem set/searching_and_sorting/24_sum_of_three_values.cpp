#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n, target;
    cin >> n;
    cin >> target;

    bool flag = true;

    vector<pair<int,int>> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx].first;
        arr[idx].second = idx;
    }

    sort(arr.begin(), arr.end());

    for (int idx = 0 ; idx < n-2 ; idx++){
        int start = idx + 1;
        int end = n-1;

        while (start < end){
            int currSum = arr[start].first + arr[end].first + arr[idx].first;
            if ( currSum == target){
                flag = false;
                cout << arr[idx].second + 1 <<  " " << arr[start].second + 1 << " " << arr[end].second + 1 << endl;
                break;
            }else if (currSum < target){
                start++;
            }else{
                end--;
            }
        }
    }

    if (flag){
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}