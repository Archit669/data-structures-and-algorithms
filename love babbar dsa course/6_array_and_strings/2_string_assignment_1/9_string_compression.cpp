#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        
        while (i<n){
            int j = i+1;
            while (j < n && chars[i] == chars[j]){
                j++;
            }
            
            // yha tb aa skte h jb yaa toh puri array traverse ho jaye
            // yaa different char mil jaye
            
            chars[ansIndex++] = chars[i];
            
            int count = j - i;
            
            if (count > 1){
                string cnt = to_string(count);
                for (char ch: cnt){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        
        return ansIndex;
    }
};