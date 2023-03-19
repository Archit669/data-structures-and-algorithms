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
    vector<int> ans;
    vector<pair<int,int>> new_arr;
    for (int i = 0 ; i < nums.size() ; i++){
        pair<int,int> tmp;
        tmp.first = nums[i];
        tmp.second = i;
        new_arr.push_back(tmp);
    }

    sort(new_arr.begin() , new_arr.end());

    int ptr1 = 0;
    int ptr2 = nums.size()-1;

    while (ptr1 <= ptr2){
        if (new_arr[ptr1].first + new_arr[ptr2].first == target){
            ans.push_back(new_arr[ptr1].second);
            ans.push_back(new_arr[ptr2].second);
            return ans;
        }else if(new_arr[ptr1].first + new_arr[ptr2].first < target){
            ptr1++;
        }else{
            ptr2--;
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;

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
