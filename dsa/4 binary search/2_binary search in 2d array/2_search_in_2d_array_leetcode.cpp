class Solution {
    bool binarySearch(vector<vector<int>>& matrix , int row , int target){
        int start = 0;
        int end = matrix[0].size() - 1;
        
        while (start <= end){
            int mid = start + (end -start)/2;
            if (matrix[row][mid] == target){
                return true;
            }else if(matrix[row][mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0 ;
        int end = m-1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (matrix[mid][0] <= target && matrix[mid][n-1] >=target){
                bool ans = binarySearch(matrix, mid,target);
                return ans;
            }
            else if (matrix[mid][0] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        return false;
    }
};