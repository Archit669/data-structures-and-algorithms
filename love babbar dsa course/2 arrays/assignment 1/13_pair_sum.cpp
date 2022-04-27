#include <bits/stdc++.h>
using  namespace std;


/*
// two sum bruteforce approach
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0 ; i < nums.size() ; i++){
        for (int j = i+1 ; j < nums.size() ; j++){
            if (nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    
    return ans;
}
*/


// two sum nlogn approach
vector<int> twoSum(vector<int>& nums, int target){
    
}






 
int main(){
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int>arr(n);
    for (int i = 0 ; i <  n ; i++){
        cin >> arr[i];
    }

    vector<int> ans = twoSum(arr,target);

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
