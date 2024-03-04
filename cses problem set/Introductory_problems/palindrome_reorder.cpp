#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    // create a map to calculate the frequency of each character
    unordered_map<char,int> charFreq;
    for (auto &ch : s){
        charFreq[ch]++;
    }

    // check how many frequency are odd
    int oddFreq = 0;
    for (auto &x : charFreq){
        oddFreq += (x.second & 1);
    }

    // if more than one frequency is odd then it is not possible to make palindrome
    if (oddFreq > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    // ans1 stores even frequency character as well as odd freq character
    string ans1;
    char oddCh = '0';
    int oddCount = 0;

    for (auto &x : charFreq){
        if (x.second & 1){
            oddCh = x.first;
            oddCount = x.second;
            continue;
        }

        int currCh = x.first;
        for (int i = 0 ; i < x.second/2 ; i++){
            ans1.push_back(currCh);
        }
    }

    for (int i = 0; i < oddCount ; i++){
        ans1.push_back(oddCh);
    }

    // ans2 stored the other half exclude the odd frequency characters
    string ans2 = ans1;
    while (oddCount != 0){
        ans2.pop_back();
        oddCount--;
    }

    reverse(ans2.begin(), ans2.end());

    // find the palindromic string
    string finalAns = ans1 + ans2;
    
    cout << finalAns << endl;

    return 0;
}