#include <bits/stdc++.h>
using namespace std;

// approach -1 bruteforce
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int count = 0;
        while ((n & (1 << count)) == 0){
            count++;
        }
        
        return count + 1;
    }
};

// approach -2  kernighan's algo
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        return log2(n & -n) + 1;
    }
};





