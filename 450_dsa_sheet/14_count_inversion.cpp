//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(long long* arr, long long start, long long end , long long mid , long long &count){
        vector<long long> arr1;
        vector<long long> arr2;
        
        for (long long i = start ; i <= mid ; i++){
            arr1.push_back(arr[i]);
        }
        
        for (long long i = mid + 1 ; i <= end ; i++){
            arr2.push_back(arr[i]);
        }
        
        
        
        long long  ptr1 = 0;
        long long ptr2 = 0;
        long long ptr3 = start;
        
        while (ptr1 < arr1.size() && ptr2 < arr2.size()){
            if (arr1[ptr1] <= arr2[ptr2]){
                arr[ptr3++] = arr1[ptr1++];
            }else{
                arr[ptr3++] = arr2[ptr2++];
                count+= arr1.size()-ptr1;
            }
        }

        while (ptr1 < arr1.size()){
            arr[ptr3++] = arr1[ptr1++];
        }
        
        while (ptr2 < arr2.size()){
            arr[ptr3++] = arr2[ptr2++];
        }
        
    }
    
    void sort(long long *arr, long long start, long long end , long long &count){
        if (start >= end) return;
        long long mid = start + (end - start)/2;
        sort(arr, start, mid, count);
        sort(arr, mid+1, end , count);
        merge(arr, start, end, mid,count);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        sort(arr, 0, N-1, count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends