// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    
    bool issafe(vector<vector<int>> &m, vector<vector<int>> &visited , int n , int x , int y){
        
        if ((x >=0 && x < n) && (y>=0 && y<n) && (visited[x][y] == 0) && (m[x][y] == 1)){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, vector<vector<int>> &visited, int n ,string &path,  vector<string> &ans,int xcor , int ycor){

        if (xcor == n-1 && ycor == n-1){
            ans.push_back(path);
            return;
        }
        
        
        visited[xcor][ycor] = 1;
        
        
        // down
        int newx = xcor+1;
        int newy = ycor;
        if (issafe(m,visited,n,newx,newy)){
            path.push_back('D');
            solve(m,visited, n , path,ans , newx, newy);
            path.pop_back();

        }
        // up
        newx = xcor-1;
        newy = ycor;
        if (issafe(m,visited,n,newx,newy)){
            path.push_back('U');
            solve(m,visited, n , path,ans , newx, newy);
            path.pop_back();

        }
        // left
        newx = xcor;
        newy = ycor-1;
        if (issafe(m,visited,n,newx,newy)){
            path.push_back('L');
            solve(m,visited, n , path,ans , newx, newy);
            path.pop_back();

        }
        // right
        newx = xcor;
        newy = ycor+1;
        if (issafe(m,visited,n,newx,newy)){
            path.push_back('R');
            solve(m,visited, n , path,ans , newx, newy);
            path.pop_back();

        }
        
        visited[xcor][ycor] = 0;
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if (m[0][0] == 0){
            return ans;
        }
        

        int xcor = 0;
        int ycor = 0;
        string path = "";
        vector<vector<int>> visited = m;
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                visited[i][j] = 0;
            }
        }
        solve(m,visited,n,path,ans,xcor,ycor);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends