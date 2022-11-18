#include <bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &arr){
    int i = 0;
    for (int j = 0 ; j < arr.size() ; j++){
        if (arr[j] < 0) swap(arr[i++], arr[j]);
    }

   vector <int> ans;

    int ptr1 = 0;
    int ptr2 = i;

    while (ptr1 < i && ptr2 < arr.size()){
        ans.push_back(arr[ptr1]);
        ans.push_back(arr[ptr2]);
        ptr1++; ptr2++;
    }

    while (ptr1 < i) ans.push_back(arr[ptr1++]);
    while (ptr2 < arr.size()) ans.push_back(arr[ptr2++]);

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0 ; i < n ; i++) cin >> arr[i];

    arr = rearrange(arr);

    for (int i = 0 ; i < n ; i++) cout << arr[i] << " "; cout << endl;

    return 0;
}