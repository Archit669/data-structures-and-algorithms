#include <iostream>
using namespace std;

int flipBits(int* arr, int n) 
{
	int flag = 1;
	int sum = 0;
	int maxi = -1;
	pair<int,int> index(0,0);
    pair<int,int> res(0,0);
	
	// if all element are one.
	for (int i = 0 ; i < n ; i++){
		if (arr[i]==0){
			flag = 0;
		}
	}
	
	if (flag == 1){
		return n;
	}
	
	
	// finding the subarray
    for (int i = 0 ; i < n ; i++){
        if (arr[i]==1){
            sum+=-1;
        }else{
            sum+=1;
        }
        if (sum > maxi){
            maxi = sum;
            index.second = i;
            res.first = index.first;
            res.second = index.second;
        }

        if (sum < 0){
            sum = 0;
            index.first = i+1;
        }
	}

	// modify given array
	for (int i = res.first ; i <= res.second ; i++){
		if (arr[i] == 0){
			arr[i] = 1;
		}else{
			arr[i] = 0;
		}
		
	}
	// calculate total no of 1's
	sum = 0;
	for (int i = 0 ; i < n ; i++){
		sum+= arr[i];
	}
	
	return sum;
}

 
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int res = flipBits(arr,n);
    cout << res << endl;


    return 0;
}