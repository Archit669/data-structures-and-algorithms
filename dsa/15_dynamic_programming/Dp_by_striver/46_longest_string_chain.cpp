#include <bits/stdc++.h>
using namespace std;

class Solution {
    // function to check whether two strings differ by exactly one character or not
    bool checkPossible(string &s1 , string &s2){

        if (s1.size() != s2.size() + 1) return false;

        int ptr1 = 0 , ptr2 = 0;
        
        while (ptr1 < s1.size()){

            if (s1[ptr1] == s2[ptr2]){

                ptr1++; ptr2++;
            }else{

                ptr1++;
            }
        }

        if (ptr1 == s1.size() && ptr2 == s2.size()) return true;

        return false;
    }

public:
    int longestStrChain(vector<string>& words) {

        // calculate the size of words array
        int n = words.size();

        // sort the words array according to the size of strings
        sort(words.begin(), words.end(), [&](string &s1 , string &s2){
            return s1.size() < s2.size();
        });

        // calculate longest possible word chain
        // this problem is similar to longest increasing subsequence
        // just instead of checking 
        // whether last number is smaller than the current one 
        // we have to check whether prev string 
        // should be differ by exactly one character
        vector<int> dp(n,1);
        int finalAns = 1;

        for (int idx = 1 ; idx < n ; idx++){

            int maxi = 0;

            for (int jdx = 0 ; jdx < idx ; jdx++){

                if (checkPossible(words[idx], words[jdx])){

                    maxi = max(maxi, dp[jdx]);
                }
            }

            dp[idx] = 1 + maxi;
            finalAns = max(finalAns, dp[idx]);
        }

        return finalAns;
    }
};