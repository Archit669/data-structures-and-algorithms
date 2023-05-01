class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();   
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int idx1 = 1 ; idx1 <= m ; idx1++){
            for (int idx2 = 1 ; idx2 <= n ; idx2++){
                if (word1[idx1-1] == word2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }else{
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }
            }
        }

        string ans;
        int ptr1 = m , ptr2 = n;
        while (ptr1 > 0 && ptr2 > 0){
            if (word1[ptr1-1] == word2[ptr2-1]){
                ans.push_back(word1[ptr1-1]);
                ptr1--; ptr2--;
            }else if (dp[ptr1-1][ptr2] >= dp[ptr1][ptr2-1]){
                ans.push_back(word1[ptr1-1]);
                ptr1--;
            }else{
                ans.push_back(word2[ptr2-1]);
                ptr2--;
            }
        }

        while (ptr1 > 0){ ans.push_back(word1[ptr1-1]); ptr1--;}
        while (ptr2 > 0) {ans.push_back(word2[ptr2-1]); ptr2--;}

        reverse(ans.begin(), ans.end());
        return ans;
    }
};