//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    void multiply(vector<int> &num1, int num2){
        int carry = 0;
        for (int i = 0 ; i < num1.size() ; i++){
            int temp = num1[i] * num2 + carry;
            num1[i] = temp%10;
            carry = temp/10;
        }
        
        while (carry){
            num1.push_back(carry%10);
            carry = carry / 10;
        }
        
    }
public:
    vector<int> factorial(int N){
        vector<int> ans = {1};
        for (int i = 2 ; i <= N ; i++){
            multiply(ans,i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends