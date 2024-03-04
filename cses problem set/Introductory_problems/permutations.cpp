// first print all the even then print all the odd 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int evenNum = n / 2;
    int oddNum = n - evenNum;

    for (int num = 1; num <= evenNum ; num++){
        cout << num*2 << " ";
    }

    for (int num = 1; num <= oddNum ; num++){
        cout << 2*num - 1 << " ";
    }

    cout << endl;
    
    return 0;
}