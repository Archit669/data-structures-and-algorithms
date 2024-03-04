#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    int mask = (1 << k);
    
    cout << (n | mask) << endl;

    return 0;
}