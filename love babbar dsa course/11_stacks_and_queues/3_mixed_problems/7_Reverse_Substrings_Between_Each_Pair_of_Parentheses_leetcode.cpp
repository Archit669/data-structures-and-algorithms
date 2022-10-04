#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == ')'){
                string temp;
                while (st.top() != '('){
                    temp+= st.top();
                    st.pop();
                }
                st.pop();
                
                for (auto &ch : temp){
                    st.push(ch);
                }
            }
            
            else{
                st.push(s[i]);
            }
            
            
        }
        
        string ans;
        while (!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};