#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (int edge = 0 ; edge < prerequisites.size()  ; edge++){
            int v = prerequisites[edge][0];
            int u = prerequisites[edge][1];
            adjList[u].push_back(v);
        }

        vector<int> indegree(numCourses);

        for (int course = 0 ; course < numCourses; course++){
            for (auto &nextCourse : adjList[course]){
                indegree[nextCourse]++;
            }
        }

        queue<int> q;
        
        for (int course = 0 ; course < numCourses; course++){
            if (indegree[course] == 0){
                q.push(course);
            }
        }

        int count = 0;

        while (!q.empty()){
            int frontCourse =  q.front();
            q.pop();

            count++;

            for (auto &nextCourse : adjList[frontCourse]){
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }

        return count == numCourses ? true : false;
    }
};