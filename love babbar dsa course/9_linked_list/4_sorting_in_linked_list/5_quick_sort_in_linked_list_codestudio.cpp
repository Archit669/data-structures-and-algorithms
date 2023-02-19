//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // for(int i = low ; i <= high ; i++) cout << arr[i]<< " "; cout << endl;
        if (low >= high) return ;
        int pi = partition(arr, low, high);
        // for(int i = low ; i <= high ; i++) cout << arr[i]<< " "; cout << endl;
        
        // recursion solve the left side
        quickSort(arr, low, pi-1);
        
        // recursion solve the right side
        quickSort(arr, pi+1, high);
        
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
        // count no of elements smaller than our first element.
        int count = 0;
        int pivot = arr[s];
        for (int i = s+1 ; i <= e ; i++){
            if (arr[s] > arr[i]){
                count++;
            }
        }
    
     
        // place pivot at its right place
        swap(arr[s] , arr[s+count]);
        int pivot_index = s+count;
    
    
        // all elements (left to pivot) ,make smaller than pivot
    
        while ( (s<e) && ((s!=pivot_index) || (e!=pivot_index)) ){
            while (arr[s] < pivot) s++;
            while ((arr[e] >= pivot)  && (e>pivot_index) ) e--;
    
            swap(arr[s],arr[e]);
    
        }
    
        return pivot_index;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
