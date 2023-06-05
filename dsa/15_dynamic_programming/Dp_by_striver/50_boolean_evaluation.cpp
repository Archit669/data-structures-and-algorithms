#include <bits/stdc++.h> 
using namespace std;
#define M (int)(1e9 + 7)
#define ll long long

vector<vector<vector<ll>>> dp;

ll f(string &exp, int i, int j, int isTrue){

    if (i > j) return 0;

    if (i == j){
        
        if (isTrue) return exp[i] == 'T';
        return exp[i] == 'F'; 
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ans = 0;

    for (int k = i ; k < j ; k+=2){

        ll cost = 0;

        ll lT = f(exp, i, k, 1);
        ll rT = f(exp, k+2, j, 1);
        ll lF = f(exp, i, k, 0);
        ll rF = f(exp, k+2, j, 0);

        if (exp[k+1] == '|'){
            
            if (isTrue) cost = ((lT * rT)%M + (lT* rF)%M + (lF* rT)%M)%M;
            else cost = (lF* rF)%M;
        }

        if (exp[k+1] == '&'){

           if (isTrue) cost = (lT * rT)%M;
           else cost = ((lF * rF)%M + (lT* rF)%M + (lF* rT)%M)%M;
        }

        if (exp[k+1] == '^'){

            if (isTrue) cost =  ((lT * rF)%M + (rT * lF)%M)%M;
            else cost = ((lT * rT)%M + (lF * rF)%M)%M;
        }

        ans = (ans%M + cost%M)%M;
    }

    return dp[i][j][isTrue] = ans%M;
};

int evaluateExp(string & exp) {

    int n = exp.size();

    dp = vector<vector<vector<ll>>>(n,vector<vector<ll>>(n, vector<ll>(2,-1)));
    return f(exp, 0, exp.size()-1, true);
}