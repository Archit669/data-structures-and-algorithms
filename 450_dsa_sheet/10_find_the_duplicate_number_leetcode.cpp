#include <bits/stdc++.h>
using namespace std;

// time complexity - O(NlogN)
//  space complexity - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int n = nums.size();

        // sort the array
        sort(begin(nums), end(nums));

        // now duplicate numbers are adjacent
        for (int i = 0 ; i < n ; i++){
            if (i != n-1 && nums[i] == nums[i+1]) return nums[i];
        }

        return -1;
    }
};


// time complexity - O(N)
// space complexity  O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // create an map to keep track of count of elements
        unordered_map<int,int> m;
        for (int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }

        // iterate map to find element count > 1
        for (auto &[key, value] : m){
            if (value > 1 ) return key;
        }

        return -1;
    }
};


// time complexity - O(N)
// space complexity - O(1)
// floyd's approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // create slow and fast pointer
        int slow = 0;
        int fast = 0;

        // move fast and slow pointer until they meet in cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);


        // find beginning of cycle
        slow = 0;

        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


// time complexity - O(N)
// space complexity - O(1)
// cycle sort

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // cycle sort the given array
        int i = 0;
        while ( i < nums.size()){
            if (nums[i] == i+1){
                i++;
            }else if (nums[i] != i+1 && nums[i] == nums[nums[i]-1]){
                i++;
            }else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        // now duplicate number is not at right position
        for (int i= 0 ; i < nums.size(); i++){
            if (nums[i] != i+1) return nums[i];
        }

        return -1;
    }
};

