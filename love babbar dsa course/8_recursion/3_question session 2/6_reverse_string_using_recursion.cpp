#include <iostream>
using namespace std;

string reverse(string str,int start = 0){
    if (start > str.size()-start-1) return str;
    swap(str[start++] , str[str.size()-start -1]);
    return reverse(str,start);
}
 
int main(){
    string str;
    getline(cin,str);
    string str2 = reverse(str);
    cout << str2 << endl;
    return 0;
}