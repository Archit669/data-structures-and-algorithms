#include <bits/stdc++.h>
using namespace std;

/*
// approach 1
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};
*/

// approach - 2

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int i = 0 , j = 0 , n = s.size() , m = part.size();
        for (i = 0 , j =0 ; i < n ; i++){
            x[j++] = s[i];
            if (j>=m && x.substr(j-m , m)== part){
                j-=m;
            }
        }
        
        return x.substr(0,j);
    }
};

