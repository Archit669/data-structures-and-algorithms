#include <bits/stdc++.h>
using namespace std;
 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int neg = 0;
    for (int i = 0 ; i < nums.size() ; i++){
        if (nums[i] < 0 ){
            swap(nums[neg], nums[i]);
             neg++;
        }
    }
    return nums;
}