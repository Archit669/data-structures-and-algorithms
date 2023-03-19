// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
        vector<int> intersection(int* arr1, int*arr2, int n1 , int n2){
            int i = 0;
            int j = 0;
            vector<int> ans;
            int val = 0;
            while (i < n1 && j < n2){
                if (arr1[i] < arr2[j]){
                    i++;
                }else if (arr1[i] > arr2[j]){
                    j++;
                }else{
                    val = arr1[i];
                    i++; j++;
                    if (ans.size()==0 || val != ans.back()){
                        ans.push_back(val);
                    }
                }
            }
            
            return ans;
        }
        
        vector<int> intersection(vector<int> arr1, int*arr2, int n1 , int n2){
            int i = 0;
            int j = 0;
            vector<int> ans;
            int val = 0;
            while (i < n1 && j < n2){
                if (arr1[i] < arr2[j]){
                    i++;
                }else if (arr1[i] > arr2[j]){
                    j++;
                }else{
                    val = arr1[i];
                    i++; j++;
                    if (ans.size()==0 || val != ans.back()){
                        ans.push_back(val);
                    }
                }
            }
            
            return ans;
        }
        
        
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> arr1 = intersection(A,B,n1,n2);
            vector<int> ans = intersection(arr1,C,arr1.size(),n3);
            
            return ans;
        }

};

// { Driver Code Starts.

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
}  // } Driver Code Ends