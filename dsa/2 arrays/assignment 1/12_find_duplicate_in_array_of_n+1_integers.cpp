#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
// aprroach using sort and  linear search
// time complexity - O(nlogn)
// space complexity - O(1)

int findDuplicate(vector<int> &arr){
    sort(arr.begin() , arr.end());
    for (int i = 0 ; i < arr.size()-1 ; i++){
        if (arr[i] == arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}
*/


/*

// aproach using frequency array
// time complexity - O(N)
// space complexity - O(N)

int findDuplicate(vector<int>& arr) {  
    int n = arr.size();
    vector<int>count(n+1);
    for (int i =0 ; i < arr.size() ;i++ ){
        count[arr[i]]++;
    }
    for (int i = 0 ; i < count.size() ; i++){
        if (count[i] > 1){
            return i;
        }
    }
    
    return -1;
}

*/


/*

// floyd's tortoise and hare
// time complexity - O(N)
// space complexity - O(1)

 int findDuplicate(vector<int>& nums) {
        int ptr1 = nums[0];
        int ptr2 = nums[0];
        
        do{
            ptr1 = nums[ptr1];
            ptr2 = nums[nums[ptr2]];
        }while (ptr1 != ptr2);
        
        ptr2 = nums[0];
        
        while(ptr1 != ptr2){
            ptr1= nums[ptr1];
            ptr2 = nums[ptr2];
        }
        
        return ptr1;
    }

*/

/*
// using swap sort
// time complexity - O(n)
// space complexity - O(1)

int findDuplicate(vector<int>& nums) {
    int i = 0;
    while(i< nums.size()){
        if (nums[i] == i+1){
            i++;
        }else{
            if (nums[nums[i]-1] != nums[i]){
                swap(nums[i] , nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        
        // loop for dry run swap sort
        // for (int i = 0 ; i < nums.size();i++){
        //     cout << nums[i] << " ";
        // }cout << endl;
    }
    
    for (int i = 0 ; i < nums.size() ; i++){
        if (nums[i] != i+1){
            return nums[i];
        }
    }
    
    return -1;
}
*/

// treat element of array as index of given array
// time complexity - O(n)
// space compexity - O(1)

int findDuplicate(vector<int>& nums) {
    for (int i = 0 ; i < nums.size() ; i++){
        if (nums[abs(nums[i])]>0){
            nums[abs(nums[i])] = - nums[abs(nums[i])];
        }else{
            return abs(nums[i]);
        }
    }
    
    return -1;
}




int main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for (int i = 0 ; i <  n ; i++){
        cin >> arr[i];
    }

    int res = findDuplicate(arr);
    cout << res << endl;
    return 0;
}