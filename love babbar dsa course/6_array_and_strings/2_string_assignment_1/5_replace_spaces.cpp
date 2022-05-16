#include <bits/stdc++.h>
using namespace std;


// approach-1
// time complexity - O(n)
// space complexity - O(n)
string replaceSpaces(string &str){
	string res;
	for (int  i = 0 ; i < str.size() ; i++){
		if (str[i] == ' '){
			res.push_back('@');
			res.push_back('4');
			res.push_back('0');
		}else{
			res.push_back(str[i]);
		}
	}
	return res;
}