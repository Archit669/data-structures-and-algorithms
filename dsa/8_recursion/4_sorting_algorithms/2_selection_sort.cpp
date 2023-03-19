// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


 // } Driver Code Ends
class Solution
{
    public:
     
    void selectionSort(int arr[], int n)
    {
        // base case 
        // agar array ka size 0 h ya array ka size 1 toh array already sorted h.
        if (n==0 || n == 1) return;
        
        // solve one case
        
        // assume smallest element at 0th index
        int mini = 0;

        // finding the minimum element of array.
        for (int i = 1 ; i < n ; i++){
            if (arr[mini] > arr[i]){
                mini = i;
            }
        }
        
        swap(&arr[mini],&arr[0]);
        
        // recursive case
        // baaki recursion smbhal lega
        // arr of 1th index se start kro and then size ko ek kam kr do.
        selectionSort(arr+1,n-1);
        
    }
};

// { Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends