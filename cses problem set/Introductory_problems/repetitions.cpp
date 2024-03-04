#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int maxLen = 1;
    int currLen = 1;

    int ptr = 1;

    while (ptr < (int)s.size()){
        if (s[ptr] == s[ptr - 1]){
            currLen++;
        }else{
            maxLen = max(currLen, maxLen);
            currLen = 1;
        }
        ptr++;
    }

    maxLen = max(maxLen, currLen);
    cout << maxLen << endl;

    return 0;
}