#include <bits/stdc++.h>
using namespace std;

void say_digit(int n){
    vector<string> s(10);
    s[0] = "zero"; s[1] = "one";  s[2] = "two";
    s[3] = "three"; s[4] = "four"; s[5] = "five";
    s[6] = "six"; s[7] = "seven"; s[8] = "eight";
    s[9] = "nine";

    if (n==0) return ;
    say_digit(n/10);
    int digit = n%10;
    cout << s[digit] << " ";
}
 
int main(){
    int n;
    cin >> n;

    say_digit(n);
    return 0;
}