#include <bits/stdc++.h>
using namespace std;


/*
// time complexity - O(n^2)
// space complexity - O(1)

class Solution {
    void move_to_end(vector<int> &arr , int i){
        int temp = arr[i];
        while (i < arr.size()-1){
            arr[i] = arr[i+1];
            i++;
        }
        arr[i] = temp;
    }
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 0;
        int i = 1;
        
        while(i < arr.size() && arr[i]!= -1000){     
            if (arr[i] == arr[i-1]){
                arr[i] = -1000;
                move_to_end(arr,i);
            }else{
                i++;
            }
        }
        
        for (int i =0 ; i < arr.size() ; i++){
            if (arr[i] != -1000){
                count++;
            }
        }    
        
        return count;
    
    }
};

*/

// approach - 2
// time complexity - O(n)
// space complexity - O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        int j = 0;    
        while (++j < arr.size()){
             if (arr[j] != arr[i]){
                 arr[++i]= arr[j];
             }
        }
        return (i+1);  
    }
};