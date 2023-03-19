//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


// // time complexity - O(N*k)
// // space complexity - O(1)
// vector<long long> printFirstNegativeInteger(long long int arr[],
//                                              long long int N, long long int K) {
                                                 
//     vector<long long> ans;
//     int i = 0;
//     int j = K-1;
    
//     while (j < N){
//         bool flag = 1;
//         for (int k = i ; k <= j; k++){
//             if (arr[k] < 0) {
//                 ans.push_back(arr[k]);
//                 flag = 0;
//                 break;
//             }
//         }
        
//         if (flag) ans.push_back(0);
        
//         i++;  j++;
//     }
    
    
//     return ans;
//  }



//  // time complexity - O(N)
//  // space complexity - O(K)

// vector<long long> printFirstNegativeInteger(long long int arr[],
//                                              long long int n, long long int k) {
//     vector<long long> ans;                                   
//     deque<long long> dq;
    
//     int i = 0;
    
//     // create a window of size k
//     for (i ; i < k ; i++){
//         if (arr[i] < 0) dq.push_back(i);
//         if (i == k-1)  break;
//     }
    
//     // now processing remaining windows
//     while (i < n){
//          // insert first negative integer of window in ans
//          if (!dq.empty()) ans.push_back(arr[dq.front()]);
//          else ans.push_back(0);
//          // slide the window
//          i++;
//          // adding element to window
//          if (arr[i] < 0) dq.push_back(i);
//          // removal elment 
//          if (!dq.empty() && i - dq.front() >= k) dq.pop_front();
//     }
    
//     return ans;
                                                 
//  }




// time complexity - O(N)
// space complexity - O(1)
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
    vector<long long> ans;                                   
    long long firstNegativeIndex = 0;
    long long firstNegativeElement;
 
    for (int i = k - 1; i < n; i++) {
 
        // skip out of window and positive elements
        while ((firstNegativeIndex < i)
               && (firstNegativeIndex <= i - k
                   || arr[firstNegativeIndex] >= 0)) {
            firstNegativeIndex++;
        }
 
        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0) {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else {
            firstNegativeElement = 0;
        }
        ans.push_back(firstNegativeElement);
    }
    
    return ans;
                                                 
 }