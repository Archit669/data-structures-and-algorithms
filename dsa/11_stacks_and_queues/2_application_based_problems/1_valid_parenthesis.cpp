#include <bits/stdc++.h>
using namespace std;


bool isValidParenthesis(string expression)
{
   stack<char> s;
   
    for (int i = 0 ; i < expression.size() ; i++){
        if (expression[i] == ']' || expression[i] == ')' ||  expression[i] == '}' ){
            if (s.empty()) return false;
            if ((s.top() == '[' && expression[i] == ']') ||
            (s.top() == '(' && expression[i] == ')') || 
            (s.top() == '{' && expression[i] == '}')){
                s.pop();
            }else{
                return false;
            }
        }
        else{
            s.push(expression[i]);
        }
       
    }
    if (s.empty()) return true;
    return false;
}