#include <bits/stdc++.h>
using namespace std;

bool check_int(float n){
    int res=n/1;
    if(res*1==n) return true;
    else return false;
}

int main(){
    float a = -2.5;
    cout << check_int(a) << " ";
    return 0;
}