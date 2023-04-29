class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size() + 1, 0);
        for (int ptr1 = 1 ; ptr1 <= text1.size() ; ptr1++){
            vector<int> curr(text2.size() + 1, 0);
            for (int ptr2 = 1 ; ptr2 <= text2.size() ; ptr2++){
                if (text1[ptr1-1] == text2[ptr2-1]){
                    curr[ptr2] = 1 + prev[ptr2-1];
                }else{
                    curr[ptr2] = max(prev[ptr2], curr[ptr2-1]);
                }
            }

            prev = move(curr);
        }

        return prev[text2.size()];
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1= s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return longestCommonSubsequence(s1, s2);
    }
};