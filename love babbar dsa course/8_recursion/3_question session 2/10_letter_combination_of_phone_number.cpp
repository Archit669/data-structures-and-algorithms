#include <bits/stdc++.h>
using namespace std;
 

class Solution {
    void solve(  vector<string> &chDigits,string &digits, string &output , vector<string> &ans,int i = 0){
        if (i>=digits.size()){
            if (output != "")
                ans.push_back(output);
            return;
        }
        for (int k = 0 ; k < chDigits[digits[i]-'0'].size() ; k++){
            int m = digits[i] - '0';
            char ch = chDigits[m][k];
            output.push_back(ch);
            solve(chDigits,digits, output,ans,i+1);   
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        vector<string> chDigits = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(chDigits,digits,output,ans);
        return ans;
    }
};