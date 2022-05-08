// time complexity - O(n^2)
// space complexity - O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0 ; i < n ; i++){
            for (int j = i+1 ; j < n ; j++){
                if (arr[i]*2 == arr[j]){
                    return true;
                }else if (arr[j]*2 == arr[i]){
                    return true;
                }
            }
        }
        
        return false;
    }
};


// time complexity - o(n)
// space complexity - O(n)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for (int i = 0; i < n ; i++){
            m[arr[i]]++;
        }
        for (int i = 0 ; i < n ; i++){
            if ((m.count(arr[i]*2)) && (m[0] > 1 || arr[i]!=0 )){
                return true;
            }
        }
        
        return false;
    }
};

// time complexity - O(nlogn)
// space complexity - O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for (int i = 0 ; i < arr.size() ; i++){
            if (arr[i] ==0 && arr[i+1]==0) return true;
            int ele = 2*arr[i];
            if (ele && binary_search(arr.begin(),arr.end(), ele)){
                return true;
            }
        }
        return false;
    }
};
