// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    
    int sum(int* arr, int n){
        int sum = 0;
        for (int i = 0 ; i < n ; i++){
            sum+=arr[i];
        }
        
        return sum;
    }
    
    int isPossible(int* arr , int size , int max_pages , int n_students){
        int pages_sum = 0;
        int student_count = 1;
        
        for (int i = 0 ; i < size ; i++){
            if (arr[i] + pages_sum  <= max_pages){
                pages_sum += arr[i];
            }else{
                student_count++;
                if (student_count > n_students || arr[i] > max_pages){
                    return false;
                }else{
                    pages_sum = arr[i];
                }
            }
        }
        
        return true;
    }
    
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start = 0;
        int end = sum(A,N);
        int ans = -1; 
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isPossible(A,N,mid,M)){
                ans = mid;
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends