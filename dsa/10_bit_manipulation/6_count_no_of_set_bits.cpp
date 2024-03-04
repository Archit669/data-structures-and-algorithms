// kernighan's algo

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int count = 0;

//     while (n != 0){
//         int rsbm = n & -n;
//         n -= rsbm;
//         count++;
//     }

//     cout << count << endl;

//     return 0;
// }


// built - in function
// cout << __builtin_popcount(n) << endl;


// approach -3

// the main intuition behind kernighan's algo is when 
// we sub a num by -1 
// then it toggles all the bits from rightmost set bit to lsb 

// so (num & (num-1)) it unset the rightmost set bit 
// and (num & ~(num-1)) it create a rightmost set bit mask

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    cout << __builtin_popcount(n) << endl;
    int count = 0;

    while (n != 0){
        n = n & (n-1);
        count++;
    }

    cout << count << endl;

    return 0;
}