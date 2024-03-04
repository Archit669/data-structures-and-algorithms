#include <bits/stdc++.h>
using namespace std;

void toh(int n, int src, int help, int des){
    if (n == 0) return;

    if (n == 1){
        cout << src << " " << des << endl;
        return;
    }

    toh(n-1, src, des, help);
    cout << src << " " << des << endl;
    toh(n-1, help, src , des);
}

int main(){
    int n;
    cin >> n;

    cout << pow(2,n) - 1 << endl;
    toh(n, 1, 2, 3);

    return 0;
}