#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr , int s , int e){
    int mid = s + (e-s)/2;
    int left_size = (mid-s)+1;
    int right_size = e - mid;

    int* left = new int[left_size];
    int* right = new int[right_size];

    int k = s;
    for (int i = 0 ; i < left_size ; i++){
        left[i] = arr[k++];
    }
    for (int i = 0 ; i < right_size ; i++){
        right[i] = arr[k++];
    }

    // merge two sorted array
    int ptr1 = 0;
    int ptr2 = 0;
    int ptr3 = s;

    while (ptr1 < left_size && ptr2 < right_size){
        if (left[ptr1] <= right[ptr2]){
            arr[ptr3++] = left[ptr1++];
        }else{
            arr[ptr3++] = right[ptr2++];
        }
    }

    while (ptr1 < left_size) arr[ptr3++] = left[ptr1++];
    while (ptr2 < right_size) arr[ptr3++] = right[ptr2++];

    delete [] left; 
    delete [] right; 
}


void mergeSort(vector<int> &arr ,int s , int e){
    if (s>=e) {
        return;
    }
    int mid = s+(e-s)/2;


    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}
 
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    return 0;
}