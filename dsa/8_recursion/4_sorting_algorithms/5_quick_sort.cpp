#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr , int s , int e){

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



void quickSort(vector<int> &arr ,int s , int e){
    // base case
    if (s>=e) {
        return;
    }

    // will give index of partition
    int p = partition(arr,s,e);

    // recursive case
    quickSort(arr, s, p-1);
    quickSort(arr,p+1,e);
}
 
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    return 0;
}