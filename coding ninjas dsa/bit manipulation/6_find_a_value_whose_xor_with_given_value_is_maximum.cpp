#include <iostream>
using namespace std;

long long findValueWhoseXORWithGivenNumberIsMaximum(long long X)
{
	long long int ans = ~X;
	long long int con = 1;
	for (int i = 0 ; i < 3 ; i++){
		ans = ans & (~(con << (61+i)));
	}
	
	return ans;
}
 
int main(){
    long long int n;
    cin >> n;

    cout << findValueWhoseXORWithGivenNumberIsMaximum(n) << endl;

    return 0;
}