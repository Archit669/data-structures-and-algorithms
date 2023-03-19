#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;  //for storing answer
        for(char i:S)  //for traversing each element in the string
        {
            if(ans.size()==0) ans.push_back(i);  //if string is empty then just push element simply...
            else if(i==ans.back()) ans.pop_back();  //or if the current element is equal to the last element of the string then it's the adjacent one, so delete it.
            else ans.push_back(i);  //else just push the element simply
        }
        return ans;  //return the string
    }
};