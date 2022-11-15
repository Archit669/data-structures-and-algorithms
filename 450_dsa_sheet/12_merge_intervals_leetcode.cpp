#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);

        for (int i = 1; i < intervals.size() ; i++){
            if (s.top()[1] >= intervals[i][0]){
                vector<int> temp;
                temp.push_back(s.top()[0]);
                temp.push_back( max(intervals[i][1] , s.top()[1]));
                s.pop();
                s.push(temp);
            }else{
                s.push(intervals[i]);
            }
        }

        vector<vector<int>> ans;
        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};