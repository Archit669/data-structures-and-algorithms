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
    int doIntersecton(int a[], int n, int b[], int m)  {
        vector<int> res;
        sort(a,a+n);
        sort(b, b+m);

        int i = 0;  // ptr1
        int j = 0;  // ptr2

        // intersection of two sorted array
        while (i < n && j < m){
            // to avoid add of duplicate element from first array
            while(i!=0 && i < n && a[i]== a[i-1]){
                i++;
            }
            // to avoid add of duplicate element from second array
            while (j!=0 && j < m && b[j] == b[j-1]){
                j++;
            }
            // if condition to check bound of arrays
            if (i < n && j < m){
                if (a[i] < b[j]){
                    i++;
                }else if (a[i] > b[j]){
                    j++;
                }else{
                    res.push_back(a[i]);
                    i++; j++;
                }
            }
        }
        // display array
        cout << "intersection of two array is : " << endl;
        for (int i = 0 ; i < res.size(); i++){
            cout << res[i] << " ";
        }cout << endl;

        // return size of array.
        cout << "size of intersection is : ";
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
	    cout << ob.doIntersecton(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends