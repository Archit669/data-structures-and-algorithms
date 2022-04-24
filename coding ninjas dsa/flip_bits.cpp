#include <iostream>
using namespace std;



int flipBits(int* arr, int n) 
{
	int sum = 0;
	int maxi = -1;
	pair<int,int> index(-1,-1);
	
    for (int i = 0 ; i < n ; i++){
		for (int j = i ;  j < n ; j++){
			sum = 0;
			for (int k = i ; k <=j; k++){
				if (arr[k]==1){
					sum+=-1;
				}else{
					sum+=1;
				}
			}
			if (sum > maxi){
                maxi = sum;
                index.first = i;
                index.second = j;
            }
		}
	}

	
	
	for (int i = index.first ; i <= index.second ; i++){
		if (arr[i] == 0){
			arr[i] = 1;
		}else{
			arr[i] = 0;
		}
		
	}

	
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