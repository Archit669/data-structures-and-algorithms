#include <bits/stdc++.h>
using namespace std;
 

void solve(string &str, string &output , vector<string> &ans , int i = 0 ){
    if (i >= str.size()){
        if (output != "")
            ans.push_back(output);
        return;
    }
    
    // exclude ch
    solve(str,output,ans,i+1);
    // include ch
    char ch = str[i];
    output.push_back(ch);
    solve(str,output,ans,i+1);
    output.pop_back();
}


vector<string> subsequences(string str){
	string output = "";
    vector<string> ans;
    
    solve(str,output,ans);
    
    return ans;
}
