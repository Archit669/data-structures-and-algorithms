#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    vector<int> s1;
    vector<int> s2;

    int ptr1 = n;
    int ptr2 = n - 1;

    s1.push_back(ptr1);
    s2.push_back(ptr2);

    int num = n - 2;

    while (num > 0)
    {
        if (ptr1 < ptr2)
        {
            ptr1 += num;
            s1.push_back(num);
        }
        else
        {
            ptr2 += num;
            s2.push_back(num);
        }

        num--;
    }

    cout << s1.size() << endl;
    for (auto &x : s1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << s2.size() << endl;
    for (auto &x : s2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}