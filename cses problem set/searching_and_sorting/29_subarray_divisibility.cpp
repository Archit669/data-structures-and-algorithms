#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }


    int sum = 0;
    int ans = 0;

    map<int,int> m;
    m[0]++;

    for (int j = 0 ; j <  n ; j++){
        sum += arr[j];
        // can use if we don't put 0 in map
        // ans += (sum%n < 0) ? (sum % n + n) == 0 : sum%n == 0;
        int rem = sum % n;
        if (rem < 0){
            rem += n;
        }
        if (m.find(rem) != m.end()){
            ans += m[rem];
        }

        m[rem]++;
    }

    cout << ans << endl;
    
    return 0;
}


// python code (gives TLE)
// n = int(input())
// arr = [int(x) for x in input().split()]

// sum = 0
// count = 0

// d = {}
// d[0] = 1


// for x in arr:
//     sum += x
//     rem = sum % n

//     if (rem in d):
//         count += d[rem]

//     if (rem in d):
//         d[rem] = d[rem] + 1
//     else:
//         d[rem] = 1


// print(count)
