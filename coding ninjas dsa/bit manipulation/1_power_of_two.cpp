#include <bits/stdc++.h>
using namespace std;

/*
// approach 1
// time complexity = O(n)
// space complexity = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0 ; i < 31 ; i++){
            // cout << "inside loop" << i<< endl;
            if (n==(int)pow(2,i)){
                return 1;
            }
        }
        return 0;
    }
};

*/



/*
// approach 2
// time complexity - O(1)
// sapce complexity - O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n> 0 && ((n&(n-1))==0));
    }
};

*/



// approach 3
// time complexity - O(1)
// space complexity - O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n> 0 && ((n&-n)==n));
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}



