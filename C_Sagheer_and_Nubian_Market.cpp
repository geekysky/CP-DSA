#include <bits/stdc++.h>
using namespace std;
#define int long long int

pair<bool, int> possible(vector<int> arr, int n, int mid, int s)
{
    // can i buy the cheapest mid items ?
    for (int i = 0; i < n; i++)
    {
        arr[i] += ((i + 1) * mid);
    }

    sort(arr.begin(), arr.end());
    // try to buy first mid items
    int temp = 0;
    for (int i = 0; i < mid; i++)
    {
        temp += arr[i];

        if (temp > s)
        {
            return {false, -1};
        }
    }

    if (temp <= s)
    {
        return {true, temp};
    }
}

signed main()
{
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0, high = n;
    int ans = high + 1, cost = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        pair<int, int> checker = possible(arr, n, mid, s);
        if (checker.first == true)
        {
            ans = mid;
            cost = checker.second;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << " " << cost << "\n";

    return 0;
}