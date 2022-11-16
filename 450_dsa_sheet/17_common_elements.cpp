//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> intersection (vector<int> arr1, int* arr2 , int m , int n){
        vector<int> ans;
        int ptr1 = 0 , ptr2 = 0;
        while (ptr1 < m && ptr2 < n){
            if (arr1[ptr1] < arr2[ptr2]){
                ptr1++;
            }
            else if (arr1[ptr1] > arr2[ptr2]){
                ptr2++;
            }else{
                if (ans.empty() || (!ans.empty() && ans.back() != arr1[ptr1]) )
                    ans.push_back(arr1[ptr1]);
                ptr1++;
                ptr2++;
            }
        }
        
        return ans;
    }
    
    vector<int> intersection (int* arr1, int* arr2 , int m , int n){
        vector<int> ans;
        int ptr1 = 0 , ptr2 = 0;
        while (ptr1 < m && ptr2 < n){
            if (arr1[ptr1] < arr2[ptr2]){
                ptr1++;
            }
            else if (arr1[ptr1] > arr2[ptr2]){
                ptr2++;
            }else{
                 if (ans.empty() || (!ans.empty() && ans.back() != arr1[ptr1]) )
                    ans.push_back(arr1[ptr1]);
                ptr1++;
                ptr2++;
            }
        }
        
        return ans;
    }
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
             vector<int> a1 = intersection(A,B,n1,n2);
             return intersection(a1, C, a1.size(), n3);
             
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends