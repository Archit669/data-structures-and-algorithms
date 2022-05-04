// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    void multiply(vector<int> &arr , int num){
       int carry = 0;
       for (int i = 0 ; i < arr.size() ; i++){
           int temp = arr[i] *num + carry;
           arr[i] = temp%10;
           carry = temp/10;
       }
       
       while (carry){
           int quot = carry%10;
           arr.push_back(quot);
           carry = carry/10;
       }
        
    }
    
    void reverse(vector<int> &arr){
        int low = 0;
        int high = arr.size()-1;
        
        while (low <= high){
            swap(arr[low],arr[high]);
            low++; high--;
        }
    }
    
public:
    vector<int> factorial(int N){
        vector<int> fact;
        fact.push_back(1);
        int i =2;
        while (i <= N){
            multiply(fact,i);
            i++;
        }
        
        reverse(fact);
        return fact;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends