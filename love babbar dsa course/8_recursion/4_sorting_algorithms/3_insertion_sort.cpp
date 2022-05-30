// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

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
    // function to swap two variables
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // base case
        // agar size 0 ya 1 h toh array already sorted h.
        if (n==0 || n==1) return;
        
        // recursive case
        // recursion apne app arr+1 se array sort krke le aayega
        insertionSort(arr+1,n-1);
        
        // solve one case
        // insert element in sorted array.
        int idx = 0;
        for (int i = 1 ; i < n ; i++){
            if (arr[i] < arr[idx]){
                swap(&arr[i],&arr[idx]);
                idx = i;
            }else{
                break;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends