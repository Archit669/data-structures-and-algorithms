// intervals scheduling problem
//  maximum no of non - overlapping intervals
// leetcode question 435-> non overlapping intervals

#include <bits/stdc++.h>
#define int long long
using namespace std;

int maxMovies(vector<array<int,2>>& movies){
    int n = movies.size();
    sort(movies.begin(), movies.end(), [&](auto &a, auto &b){
        return a[1] < b[1];
    });

    int count = 1;
    int prevEndTime = movies[0][1];

    for (int idx = 1 ; idx < n ; idx++){
        if (movies[idx][0] >= prevEndTime){
            count++;
            prevEndTime = movies[idx][1];
        }
    }

    return count;
}

signed main(){
    int n;
    cin >> n;

    vector<array<int,2>> movies;
    for (int idx = 0 ; idx < n ; idx++){
        int a,b;
        cin >> a >> b;

        movies.push_back({a,b});
    }

    cout << maxMovies(movies) << endl;

    return 0;
}