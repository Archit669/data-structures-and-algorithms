// time complexity of code is O(M+N)log(M+N)
// space complexity of code is O(M+N)

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        vector<int> res;
        sort(a,a+n);
        sort(b, b+m);

        int i = 0;  // ptr1
        int j = 0;  // ptr2

        // finding union of two sorted array

        while (i < n && j < m){

            // avoid to add duplicate elements
            while(i!= 0 && i < n && a[i] == a[i-1]){
                i++;
            }

            while(j!=0 && j < m && b[j] == b[j-1]){
                j++;
            }
            // if condition to avoid out of bound
            if (i < n && j < m){
                // if element of first array is less than element of second array
                if (a[i] < b[j]){
                    res.push_back(a[i]);
                    i++;
                // if element of first array is equal to second element of array
                }else if (a[i] == b[j]){
                    res.push_back(a[i]);
                    i++; j++;
                // if element of first array is greater than element of second array
                }else{
                    res.push_back(b[j]);
                    j++;
                }
            }
        }
        
        // add remainng elements in first array
        while (i < n){
            // to avoid add duplicate elements in array
            while(i!= 0 && a[i] == a[i-1]){
                i++;
            }
            // if condition to avoid out of bound
            if (i < n){
                res.push_back(a[i]);
                i++;
            }
        }

        // add remaining elements in second array
        while (j < m){
            while(j!=0 && b[j] == b[j-1]){
                j++;
            }
            if (j < m){
                res.push_back(b[j]);
                j++;
            }
        }

        // display array
        cout << "union of two array is : " << endl;
        for (int i = 0 ; i < res.size(); i++){
            cout << res[i] << " ";
        }cout << endl;

        // return size of array.
        return res.size();

    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends