#include <bits/stdc++.h>
using namespace std;

/*
// time complexity - O(n)
// space complexity - O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> arr(nums.size()+1);
        vector<int> ans;
        for (int i = 0 ; i < nums.size() ; i++){
            arr[nums[i]]++;
        }
        
        
        for (int i = 0 ; i < arr.size() ; i++){
            if (arr[i]> 1){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};

*/


/*

// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }else{
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
        
};

*/

// using swap sort
// time complexity - O(n)
// space complexity - O(1)
// modify the array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i< nums.size()){
            if (nums[i] == i+1){
                i++;
            }else{
                if (nums[nums[i]-1] != nums[i]){
                    swap(nums[i] , nums[nums[i]-1]);
                }else{
                    i++;
                }
            }
            
        }
        
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i] != i+1){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
