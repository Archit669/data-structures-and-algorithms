#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26);
        vector<int> count2(26);
        if (s1.size() > s2.size()){
            return false;
        }
        // count occurence of all characters in string 1
        for (int i = 0 ; i < s1.size() ; i++){
            count1[s1[i] - 'a']++;
        }
        // create a window of size s2 and traverse through s1 and compare
        
        int i = 0, j = s1.size();
        
        // traverse for first window
        for ( ; i < j ; i++){
            count2[s2[i]-'a']++;
        }
        
       if (count1 == count2) return true;
       
        // traverse for remaining window.
       i = 0 ; j = s1.size();
       while (j < s2.size()){
           count2[s2[i]-'a']--;
           count2[s2[j]-'a']++;
           i++; j++;
           if (count1 == count2) return true;
       }
        
       return false;
    }
};