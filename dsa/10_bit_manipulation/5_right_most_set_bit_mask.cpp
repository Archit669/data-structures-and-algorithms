#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    // formula : n & 2's compliment(n)
    // 2's compliment of x = ~x + 1
    int rightMostSetBitMask = n & -n;  

    cout << rightMostSetBitMask << endl;

    cout << "mask is " << endl;
    cout << bitset<64>(rightMostSetBitMask).to_string() << endl;

    return 0;
}