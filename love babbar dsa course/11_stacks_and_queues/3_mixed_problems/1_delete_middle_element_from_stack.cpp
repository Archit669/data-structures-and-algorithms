#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&s , int count , int size){
    if (count == size/2){
        s.pop();
        return;
    }
    int element = s.top();
    s.pop();
    solve (s, count+1, size);
    s.push(element);
}

void deleteMiddle(stack<int>&inputStack, int N){
    solve(inputStack,0,N);
    return;
}