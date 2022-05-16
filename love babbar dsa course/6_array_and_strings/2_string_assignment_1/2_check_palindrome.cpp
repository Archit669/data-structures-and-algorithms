#include <string>
using namespace std;

bool checkPalindrome(string s)
{
    int start = 0;
	int end = s.size()-1;
	
	while (start < end){
		if (!iswalnum(s[start])) start++;
		else if(!iswalnum(s[end])) end--;
		
		else if (isupper(s[start]))  s[start]= s[start]+32;
		else if (isupper(s[end]))    s[end] = s[end]+32;
		
		
		else if (s[start] == s[end]){
			start++; end--;
		}else{
			return false;
		}	
	}
	return true;
}