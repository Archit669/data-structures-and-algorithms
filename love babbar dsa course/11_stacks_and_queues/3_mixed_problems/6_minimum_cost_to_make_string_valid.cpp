#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
     if (str.length() & 1) return -1;
      stack<char> stk;
      for (int i = 0 ; i < str.size() ; i++){
          if (str[i] == '{') stk.push(str[i]);
          else{
              if (!stk.empty() && stk.top() == '{') stk.pop();
              else stk.push(str[i]);
          }
      }
    
     int a = 0;
     int b = 0;
     
     while (!stk.empty()){
         if (stk.top() == '{') a++;
         else b++;
         stk.pop();
     }
    
    
     int ans = (a+1)/2 + (b+1)/2;
     return ans;
}