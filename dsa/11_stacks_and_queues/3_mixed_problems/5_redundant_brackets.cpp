#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> stk;
    
    for (int i = 0 ; i < s.size() ; i++){
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            stk.push(s[i]);
        }else{
            if (s[i] == ')'){
                bool isRedundant = 1;
                while (!stk.empty() && stk.top() != '('){
                    char ch = stk.top();
                    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                        stk.pop();
                        isRedundant = 0;
                    }
                }
                stk.pop();
                if (isRedundant) return true;
            }
        }
    }
    
    return false;
}
