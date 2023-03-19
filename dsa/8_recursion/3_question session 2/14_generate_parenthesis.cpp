#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void solve(vector<string> &result,string &output,int openBraces,int closeBraces,int curropen , int currclose){
        
        if (openBraces == 0 && closeBraces == 0)
        {
            result.push_back(output);
            return;
        }
        
        // call for open braces
        if (openBraces)
        {
            // push open braces in output string
            output.push_back('(');
            // recursive call
            solve(result, output, openBraces-1, closeBraces, curropen+1, currclose);
            // bractraking (pop open brace from output string)
            output.pop_back();
        }
        
        // call for close braces
        if (closeBraces && (currclose < curropen))
        {
            // push close braces in output string
            output.push_back(')');
            // recursive call
            solve(result, output, openBraces, closeBraces-1, curropen, currclose+1);
            // bractraking (pop close brace from output string)
            output.pop_back();
        }    
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
        // create a result vector which will store all combination of well formed parenthesis
        vector<string> result;
        
        // create ouput string  which will store well formed parenthesis
        string output = "(";
        
        // variable to store no of opening and closing braces
        int openBraces = n-1;
        int closeBraces = n;
        
        // variable to store no of current opening and closing braces
        int currclose = 0;
        int curropen = 1;
        
        // recursive call for solve 
        solve(result,output,openBraces,closeBraces,curropen , currclose);
        
        // return result 
        return result;      
    }
};