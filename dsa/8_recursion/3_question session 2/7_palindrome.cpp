#include <iostream>
using namespace std;

bool palindrome(string str,int start=0){
    if (start >= str.size()-start-1) return true;
    if (str[start] != str[str.size()-start-1]) return false;
    start++;
    return palindrome(str,start);
}
 
int main(){
    string str;
    getline(cin,str);
    bool ans = palindrome(str,0);
    cout << ans << endl;
    return 0;
}