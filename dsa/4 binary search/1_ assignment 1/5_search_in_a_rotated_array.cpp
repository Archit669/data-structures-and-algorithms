// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int pivot_index(int*arr, int low , int high){
        int ans = arr[0];
        while (low <= high){
            int mid = (low + (high - low)/2);
            if (arr[mid] < arr[0]){
                ans = mid;
                high = mid - 1;
            }else if (arr[mid] >= arr[0]){
                low = mid+1;
            }
        }
        return ans;
    }
    
    int binary_search(int* arr ,int low ,int high,int key){
        while (low <= high){
            int mid = (low + (high - low)/2);
            if (arr[mid] == key){
                return mid;
            }else if (arr[mid] < key){
                low = mid +1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
    public:
    int search(int A[], int l, int h, int key){
        int pivot = pivot_index(A,l,h);
        int ans = binary_search(A,l,pivot-1,key);
        if (ans != -1){
            return ans;
        }else{
            int ans = binary_search(A,pivot,h,key);
            return ans;
        }
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends