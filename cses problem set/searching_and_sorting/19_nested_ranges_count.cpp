#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

struct range{
    int l , r , index;
};

signed main(){
    int n;
    cin >> n;

    pbds A;

    vector<range> ranges(n);
    vector<int> contains(n);
    vector<int> contained(n);

    for (int idx = 0 ; idx < n ; idx++){
        int a,b;
        cin >> a >> b;

        ranges[idx].l = a;
        ranges[idx].r = b;
        ranges[idx].index = idx;
    }

    sort(ranges.begin(), ranges.end(), [&](auto &a, auto &b){
        if (a.l == b.l){
            return a.r > b.r;
        }

        return a.l < b.l;
    });

    
    // for contained we will traverse from start to end
    // at particular index i , all those previous pairs will
    // contain pair at index i , if r(right boundary) is greater than or equal to right boundary of current index

    for (int idx = 0 ; idx < n ; idx++){

        int currRightBoundary = ranges[idx].r;
        A.insert({currRightBoundary, -1*idx});

        // ele count is no of elements scrictly smaller than curr pair
        int eleCount = A.order_of_key({currRightBoundary, -1*idx});
        contained[ranges[idx].index] = A.size() - eleCount - 1;
    }

    A.clear();

    // for contains we will traverse from end to start
    // at particular index i , all the pairs below curr index
    //  contained by the index i. if right boundary is less than or equal to right boundary of current

    for (int idx = n -1 ; idx >= 0 ; idx--){
        int currRightBoundary = ranges[idx].r;
        A.insert({currRightBoundary, -1*idx});

        // ele count is no of elements scrictly smaller than curr pair
        int eleCount = A.order_of_key({currRightBoundary, -1*idx});
        contains[ranges[idx].index] = eleCount;
    }
    
    // print contains -> no of pairs contained by the curr pair
    for (auto &x : contains) {
        cout << x << " ";
    } cout << endl;

    // print contained -> no of pairs contains the curr pair
    for (auto &x : contained) {
        cout << x << " "; 
    } cout << endl;

    return 0;

}