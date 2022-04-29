#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
// approach 1 with 
// time complexity of O(nlogn)
// space complexity of o(n)


bool uniqueOccurrences(vector<int>& arr) {
    vector<int> ans;
    sort(arr.begin() , arr.end());
    int count = 0;
    for (int i = 0 ; i < arr.size() ; i++){
        count++;
        if ((i == arr.size()-1 || arr[i] != arr[i+1])){
            ans.push_back(count);
            count = 0;
        }
    }
    
    sort (ans.begin(),ans.end());
    for (int i = 0 ; i < ans.size() ; i++){
        if (i < ans.size()-1 && ans[i] == ans[i+1]){
            return false;
        }
    }
    
    return true;
}

*/


// approach 2 with
// time complexity - O(N)
// space complexity - O(1) // limited to constraints of leetcode
bool uniqueOccurrences(vector<int>& arr) {
    int arr1[2001] = {0};
    int arr2[1001] = {0};
    
    for (int i = 0 ; i < arr.size() ; i++){
        arr1[arr[i]+1000]++;
    }
    int counter = 0;
    for (int i = 0 ; i < 2001 ; i++){
        if (arr1[i] > 0){
            arr2[arr1[i]]++;
            
        }
    }
    
    for (int i =0 ; i < 1000 ; i++){
        if (arr2[i] > 1){
            return false; 
        } 
    }
    
    return true;
}
 
int main(){
    
    return 0;
}