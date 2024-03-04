#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> order;

        while (!q.empty()){
            int frontCourse =  q.front();
            q.pop();

            order.push_back(frontCourse);

            for (auto &nextCourse : adjList[frontCourse]){
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};