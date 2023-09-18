#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n , x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int idx = 0; idx < n ; idx++){
        cin >> arr[idx];
    }

    sort(arr.begin() , arr.end());
    int count = 0;
    int person1 = 0;
    int person2 = n-1;

    while (person1 < person2){
        if (arr[person1] + arr[person2] <= x){
            count++;
            person1++; person2--;
        }else{
            count++;
            person2--;
        }
    }

    if (person1 == person2){
        count++;
    }

    cout << count << endl;
    
    return 0;
}