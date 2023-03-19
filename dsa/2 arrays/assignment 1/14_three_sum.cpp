#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    // check whether size of array is greater than 3 or not.
    // if size of array is less than 3 then there is no triplet
    // so return empty vector of triplets.
    if (nums.size()<3){
        return {};
    }
    // sort the given array
    sort(nums.begin(),nums.end());
    
    // check whether first element is greater than zero or not
    // if first element is positive then there will be no triplet 
    // which sum is zero.
    if (nums[0] > 0){
        return {};
    }
    
    vector<vector<int>> ans;
    
    // iterate an array to fix one number at a time
    for (int i = 0 ; i < nums.size(); i++){
        int low = i+1;  int high = nums.size()-1; int sum = 0;
        // if number is positive then possiblity of getting triplet vanishes
        if (nums[i] > 0){
            break;
        }
        // to avoid duplicate triplets we will avoid to fix repeated numbers
        if (i> 0 && nums[i] == nums[i-1]){
            continue;
        }
        while (low < high){
            sum = nums[i] + nums[low] + nums[high];
            if (sum < 0){
                low++;
            }else if (sum > 0){
                high--;
                
            }else{
                ans.push_back({nums[i],nums[low],nums[high]});
                int last_low = nums[low] ; int last_high = nums[high];
                
                while (low < high && nums[low] == last_low)  low++;
                while (low < high && nums[high] == last_high) high--;
                
            }
        }
    }
    
    return ans;
    
}

int main(){
    int n; 
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }

    vector<vector<int>> ans = threeSum(arr);
    cout << "{ ";
    for (int i = 0 ; i < ans.size(); i++){
        cout << "[ ";
        for (int j = 0 ; j < 3 ; j++){
            cout << ans[i][j] << " ";
        }cout << "] ";
    }cout << " } " << endl;

    return 0;
}

 
