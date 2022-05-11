#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &stalls , int k , int mid){
	int cow = 1;
	int lastPos = stalls[0];
	
	for (int i = 0 ; i < stalls.size() ; i++){
		if (stalls[i] - lastPos >= mid){
			cow++;
			if (cow == k){
				return true;
			}
			lastPos = stalls[i];
		}
	}
	
	return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
	
	sort (stalls.begin() , stalls.end());
    int start = 0;
	int end = stalls[stalls.size()-1];
	int ans = -1;
	
	while (start <= end){
		int mid = start + (end - start)/2;
		if (ispossible(stalls,k,mid)){
			ans = mid;
			start = mid +1;
		}else{
			end = mid - 1;
		}
	}
	
	return ans;
	
}

int main(int argc, char const *argv[])
{
    vector<int> stalls = {1,2,3,4,5};

    cout << aggressiveCows(stalls, 3) << endl;

    return 0;
}
