#include <bits/stdc++.h>
using namespace std;

int max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

bool isPossible(int *arr, int n, int m, int max_height)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] - max_height) > 0)
        {
            sum += arr[i] - max_height;
        }
    }

    if (sum >= m)
    {
        return true;
    }

    return false;
}

int max_height(int *arr, int n, int m)
{
    int start = 0;
    int end = max(arr, n);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = max_height(arr, n, m);
    cout << res << endl;
    return 0;
}