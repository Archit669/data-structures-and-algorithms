#include <iostream>
#include <vector>
using namespace std;

long long maxSumSubarray(vector<int> arr,int n){
	long long sum = 0;
	long long maxi = arr[0];
	
	for (int i = 0 ;  i<n ; i++){
		sum+=arr[i];
		maxi = max(sum,maxi);
		if (sum < 0){
			sum = 0;
		}
	}
	return maxi;
}

long long maxSumSubarrayOfTwo(vector<int> arr,int n){
	for (int i = 0 ; i < n ; i++){
		arr.push_back(arr[i]);
	}
    long long ans = (maxSumSubarray(arr,2*n));
	return ans;
}


long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
	long long sum = 0;
    for (int i = 0 ; i < n ; i++){
        sum+= arr[i];
    }
	if (k==1){
		return maxSumSubarray(arr,n);
	}
	else if (sum < 0){
		return (maxSumSubarrayOfTwo(arr,n));
	}
	else{
		return (maxSumSubarrayOfTwo(arr,n) + (k-2)*sum);
	}
	
	return -1;
	
}
 
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    int k;
    cin >> k;

    for (int i=0 ; i < n ; i++){
        cin >> arr[i];
    }


    long long res = maxSubSumKConcat(arr,n,k);
    cout << res << endl;


    return 0;

}