#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        
        for (int i =2 ; i < sqrt(num) ; i++){
            if (num%i == 0){
                sum+=i+num/i;
            }
        }
        
        return (sum == num && num!=1);
        
    }
};