#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void solve(string &tiles,set<string> &result, string &output,map<int,bool> &flag){
        
        // make a recursive call for each character
        for (int i = 0 ; i < tiles.size() ; i++){
            // if character is not already used
            if (flag[i] == 0){ 
                // put that character in output string.
                char ch = tiles[i];
                output.push_back(ch);
                // make a flag that now that character has used.
                flag[i] = 1;
                
                // insert ouput in result
                result.insert(output);
                // make recursive call for other characters
                solve(tiles, result, output,flag);
                
                // backtracking
                output.pop_back();
                // remove flag from given character
                flag[i] = 0;  
            }
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        set<string> result;
        string output = "";
        map<int,bool> flag;
        
        solve(tiles,result,output,flag);
        return result.size();
        
    }
};