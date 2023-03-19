#include <bits/stdc++.h>
using namespace std;

/*
// approach - 1
class Solution {
    
    void reverseword(string &s , int low , int high){
        while (low <= high){
            swap(s[low++],s[high--]);
        }
    }
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        int len = s.size();
        int wordcount = 0;
        
        while(true){
            while (i < len && s[i] == ' ') i++;
            if (i==len) break;
            
            if (wordcount)  s[j++] = ' ';
            int l = j;
            
            while (i < len && s[i] != ' ') s[j++] = s[i++];
            reverseword(s,l,j-1);
            wordcount++;
        }
        
        s.resize(j);
        reverseword(s,0,j-1);
        
        return s;
    }
};
*/



// approach 2- 
// time complexity O(n)
// space complexity O(n)

string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp)
        words.push_back(tmp);

    string ans;
    for (int i = words.size() - 1; i >= 0; --i) {
        if (i != words.size() - 1) ans += " ";
        ans += words[i];
    }
    return ans;
}

/*
// approach 3

string substr(string s, int i , int j){
    string res;
    while (i<=j){
        res+=s[i];
        i++;
    }
    return res;
}

string reverseWords(string s) {
    int i = s.length()-1;
    int j = s.length()-1;
    string res = "";
    
    while(i>=0){
        while (i>=0 && s[i] == ' ') i--;
        j = i;
        if (i < 0) break;
        while (i>=0 && s[i]!= ' ') i--;
        
        if (res.empty()){
            res+= substr(s,i+1,j);
        }else{
            res+= ' ' + substr(s,i+1,j);
        }
    }
    
    return res;
}
*/



int main(int argc, char const *argv[])
{
    string str = "    the sky is blue ";
    cout << reverseWords(str) << endl;
    return 0;
}
