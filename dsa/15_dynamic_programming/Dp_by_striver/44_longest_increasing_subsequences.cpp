#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // calculate size of nums array
        const int n = nums.size();
        
        // function to calculate length of lis
        function <int(int,int)> getLis = [&](int currIdx, int prevIdx){

            // all index exhaused then there is no lis
            if (currIdx == n) {
                return 0;
            }

            // take the current index
            // if the value at current index is greater than previous index
            int take = 0;
            if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]){
                take += 1 + getLis(currIdx+1, currIdx);
            }   

            // ignore the value at current index
            int notTake = getLis(currIdx + 1, prevIdx);

            // return max of both choices
            return max(take, notTake);
        };

        // return length of longest increasing subsequence
        return getLis(0, -1);
    }
};

// memoization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // calculate size of nums array
        const int n = nums.size();

        // create an dp array
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        
        // function to calculate length of lis
        function <int(int,int)> getLis = [&](int currIdx, int prevIdx){

            // all index exhaused then there is no lis
            if (currIdx == n) {
                return 0;
            }

            // return already calculated subproblems
            // +1 for 1 based indexing in prevIdx
            if (dp[currIdx][prevIdx+1] != -1){
                return dp[currIdx][prevIdx+1];
            }

            // take the current index
            // if the value at current index is greater than previous index
            int take = 0;
            if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]){
                take += 1 + getLis(currIdx+1, currIdx);
            }   

            // ignore the value at current index
            int notTake = getLis(currIdx + 1, prevIdx);

            // return max of both choices
            return dp[currIdx][prevIdx+1] = max(take, notTake);
        };

        // return length of longest increasing subsequence
        return getLis(0, -1);
    }
};

// tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // calculate size of nums array
        const int n = nums.size();

        // create an dp array
        vector<vector<int>> dp(n+1 , vector<int>(n+1,0));

        for (int currIdx = n-1 ; currIdx >= 0 ; currIdx--){
            for (int prevIdx = n-1 ; prevIdx >= -1 ; prevIdx--){

                // take the current index
                // if the value at current index is greater than previous index
                // +1 for 1 based indexing of prevIdx in dp array
                int take = 0;
                if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]){
                    take += 1 + dp[currIdx+1][currIdx+1];
                }

                // ignore the value at current index
                // +1 for 1 based indexing in dp array
                int notTake = dp[currIdx + 1][prevIdx+1];

                // return max of both choices
                dp[currIdx][prevIdx+1] = max(take, notTake);
            }
        }

        // return length of longest increasing subsequence
        return dp[0][0];
    }
};

// space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // calculate size of nums array
        const int n = nums.size();

        // create an dp array
        vector<int> curr(n+1, 0), next(n+1,0);

        for (int currIdx = n-1 ; currIdx >= 0 ; currIdx--){
            for (int prevIdx = n-1 ; prevIdx >= -1 ; prevIdx--){

                // take the current index
                // if the value at current index is greater than previous index
                // +1 for 1 based indexing of prevIdx in dp array
                int take = 0;
                if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]){
                    take += 1 + next[currIdx+1];
                }

                // ignore the value at current index
                // +1 for 1 based indexing in dp array
                int notTake = next[prevIdx+1];

                // return max of both choices
                curr[prevIdx+1] = max(take, notTake);
            }

            next = curr;
        }

        // return length of longest increasing subsequence
        return next[0];
    }
};


/**
 * approach -2 
 * this is direct tabulation approach and little time and space optimized than above one
 * 
*/

// O(n^2 + n) time complexity
// O(n) space complexity
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // size of nums array
        const int n = nums.size();

        // create a dp array
        // each index of dp array will store ,
        // the length of longest increasing subsequence end at that index
        vector<int> dp(n, 0);

        // length of longest increasing subsequences end at index 0 is 1;
        dp[0] = 1;

        for (int idx = 1 ; idx < n ; idx++){

            // find the length of prev longest increasing subsequences
            // that can continue with current index and form lis
            int maxi = 0;
            for (int jdx = 0 ; jdx < idx ; jdx++){
                if (nums[jdx] < nums[idx]){
                    maxi = max(dp[jdx], maxi);
                }
            }

            // store the length of lis that end at curr index
            dp[idx] = 1 + maxi;
        }

        // return length of longest increasing subsequence
        return *max_element(dp.begin(), dp.end());
    }
};


// ommit , traversal for finding max element.
// tc - O(n)
// sc - O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // size of nums array
        const int n = nums.size();

        // variable to store longest increasing subsequence
        int ans = 1;

        // create a dp array
        // each index of dp array will store ,
        // the length of longest increasing subsequence end at that index
        vector<int> dp(n, 0);

        // length of longest increasing subsequences end at index 0 is 1;
        dp[0] = 1;

        for (int idx = 1 ; idx < n ; idx++){

            // find the length of prev longest increasing subsequences
            // that can continue with current index and form lis
            int maxi = 0;
            for (int jdx = 0 ; jdx < idx ; jdx++){
                if (nums[jdx] < nums[idx]){
                    maxi = max(dp[jdx], maxi);
                }
            }

            // store the length of lis that end at curr index
            dp[idx] = 1 + maxi;

            // upadate ans if we get larger increasing subsequence than previous one
            ans = max(ans, dp[idx]);
        }

        // return length of longest increasing subsequence
        return ans;
    }
};


/**
 * approach - 3
 * using binary search
 * this is most efficient approach to find length of longest increasing subsequence
 * tc - O(nlogn)
 * sc - O(n)
 * 
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // size of nums array
        const int n = nums.size();

        // create a dp array
        // lis array have length same as longest increasing subsequence at end.
        vector<int> lis;

        // initially push first element in lis
        lis.push_back(nums[0]);

        for (int idx = 1 ; idx < n ; idx++){

            // if current element is greater than the previous one
            // then it can contribute in lis
            if (nums[idx] > lis.back()){
                lis.push_back(nums[idx]);
            }else{
                // the current element is smaller 
                // it is somewhere can replace bigger element in lcs
                // that helps in forming more longer lis
                int index = lower_bound(begin(lis), end(lis) , nums[idx]) - begin(lis);
                lis[index] = nums[idx];
            }
        }

        // return length of longest increasing subsequence
        return lis.size();
    }
};