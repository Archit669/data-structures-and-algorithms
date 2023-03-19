#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        
        while (start < end){
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            
            else if (isupper(s[start])) s[start] = s[start] + 32;
            else if (isupper(s[end])) s[end] = s[end] + 32;
            
            else if (s[start] == s[end]){
                start++; end--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};