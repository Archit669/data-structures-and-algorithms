#include <iostream>
using namespace std;

void reverse(string &str){
    int start = 0 ;
    int end = str.length()-1;

    while (start <= end){
        swap(str[start],str[end]);
        start++; end--;
    }
}
 
int main(){
    string str;
    getline(cin,str);

    reverse(str);

    cout << str << endl;

    return 0;
}