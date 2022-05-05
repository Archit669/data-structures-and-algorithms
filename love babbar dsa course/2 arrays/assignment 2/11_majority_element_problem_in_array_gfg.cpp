// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

/*

// time complexity - O(n)
// space complexity - O(n)
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array

    int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int> m;
        int ans = -1;
        
        for (int i = 0 ; i < size ; i++){
            m[a[i]]++;
        }
        
        for (auto it: m){
            if (it.second > size/2){
                ans = it.first;
            }
        }
        
        return ans;
        
    }
};

*/

// time complexity - O(N)
// space complexity - O(1)

class Solution{
  public:
  
    // find candidate function
    int findCandidate(int *arr,int n){
        int maj_index = 0;
        int count = 1;
        for (int i = 1 ; i < n ; i++){
            if (arr[i] == arr[maj_index]){
                count++;
            }else{
                count--;
            }
            if (count == 0){
                maj_index = i;
                count = 1;
            }
        }
        return arr[maj_index];
    }
    
    // check ismajority function
    int ismajority(int *arr,int n,int cand){
        int count = 0;
        for (int i = 0 ; i < n ; i++){
            if (arr[i] == cand){
                count++;
            }
        }
        if (count > (n/2)){
            return true;
        }
        
        return false;
    }
  
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int cand = findCandidate(a,size);
        
        if (ismajority(a,size,cand)){
            return cand;
        }
        
        
        return -1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends