#include <bits/stdc++.h>
#define int long long
using namespace std;

// we get minimum sum of prefix sum of particular array when it is sorted
// in this question , deadlines can be rearranged in any order the main task is to minimize the prefix sum

signed main(){
    int n;
    cin >> n;

    vector<int> v(n);
    int deadLineSum = 0;

    for (int idx = 0 ; idx < n ; idx++){
        int a, b;
        cin >> a >> b;

        v.push_back(a);
        deadLineSum += b;
    }

    sort(v.begin(), v.end());
    partial_sum(begin(v), end(v), begin(v));

    int taskSum = accumulate(v.begin(), v.end(), 0);
    cout << deadLineSum - taskSum << endl;
    
    return 0;
}


// python code

// from itertools import accumulate

// n = int(input())
// v = list()

// deadLine = 0

// for i in range(n):
//     arr = [int(x) for x in input().split()]
//     v.append(arr[0])
//     deadLine += arr[1]

// v.sort()
// print(deadLine - sum(list(accumulate(v))))