// anagram -> same character , ordering different

#include <bits/stdc++.h>
using namespace std;

bool anagram(string str1 , string str2){
    vector<int> freqarr(26);

    for (int i = 0 ; i < str1.size() ; i++){
        freqarr[str1[i]-'a']++;
    }

    for (int i = 0 ; i < str2.size() ; i++){
        freqarr[str2[i]-'a']--;
    }

    for (int i = 0 ; i < freqarr.size() ; i++){
        if (freqarr[i] != 0){
            return 0;
        }
    }

    return 1;

}
 
int main(){
    string str1;
    getline(cin,str1);
    string str2;
    getline(cin,str2);

    cout << anagram(str1, str2) << endl;

    return 0;
}