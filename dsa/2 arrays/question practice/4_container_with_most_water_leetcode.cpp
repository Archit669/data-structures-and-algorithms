
// bruteforce 
// time complexity - O(N^2)
// space complexity - O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        for (int i = 1 ; i <= height.size() ; i++){
            for (int j = i+1 ; j <= height.size() ; j++){
                int minHeight = min(height[i-1],height[j-1]);
                int base = j - i;
                ans = max(ans,base*minHeight);
            }
        }
        
        return ans;
    }
};