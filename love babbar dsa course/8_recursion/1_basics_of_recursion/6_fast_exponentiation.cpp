#include <iostream>
using namespace std;

int pow(int x,int n){
    int ans = 1;
    if (n==0){
        return 1;
    }
    
    int cp = pow(x,n/2);

    if (n&1){
        ans = cp*cp*x;
    }else{
        ans = cp*cp;
    }
    return ans;
}

 
int main(){
    int x , n;
    cin >> x >> n;

    cout << pow(x,n) << endl;
    return 0;
}