// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array

    // bruteforce approach 
    // time complexity - O(n2)
    // space complexity - O(1)
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        for (int i = 0 ; i < N ; i++){
            for (int j = i+1 ; j < N ; j++){
                if (arr[i] > arr[j]) count++;
            }
        }
        
        return count;
    }
    
    long long int merge(long long int arr[] , int l , int r){
        long long count = 0;
        int mid = l + (r-l)/2;
        int left_size = mid-l+1;
        int right_size = r - mid;
        
        long long int *left = new long long int[left_size];
        long long int *right = new long long int[right_size];
        
        int k = l;
        
        for (int i = 0 ; i < left_size ; i++){
            left[i] = arr[k++];
        }
        for (int i = 0 ; i < right_size ; i++){
            right[i] = arr[k++];
        }
        
        int i = 0;
        int j = 0;
        k = l;
        
        while (i < left_size && j < right_size){
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else{
                 arr[k++] = right[j++];
                 count+= left_size - i;
            }
                
        }
        
        while (i < left_size) arr[k++] = left[i++];
        while (j < right_size) arr[k++] = right[j++];
        
        return count;
        
        
    }
    
    long long int solve(long long arr[], int l , int r){
        if (l >= r) return 0;
        
        long long int count = 0;
        
        int mid = l + (r - l)/2;
        
        count+=solve(arr,l,mid);
        count+=solve(arr,mid+1,r);
        
        count+= merge(arr, l,r);
        
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = solve(arr, 0 , N-1);
        
        return ans;
    }

};

// { Driver Code Starts.

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