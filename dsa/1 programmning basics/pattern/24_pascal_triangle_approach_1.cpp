#include <iostream>
#include <math.h>
using namespace std;

double factorial(int n){
    if (n==0){
        return 1;
    }
    return (n*factorial(n-1));
}

double combination(int n,int r){
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}
 
int main(){
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ;  j <= i ; j++){
            cout << combination(i,j) << " ";
        }cout << endl;
    }cout << endl;
    return 0;
}