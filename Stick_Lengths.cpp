#include <bits/stdc++.h>
using namespace std;
#define int long long int

int total_cost(vector<int> &arr, int n, int x)
{
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(arr[i] - x);
    }
    return cost;
}

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    sort(arr.begin(), arr.end());
    auto it = mp.begin();

    int mean;
    for (int i = 0; i < n; i++)
    {
        mean += arr[i];
    }
    mean /= n;

    int median = arr[n / 2];

    int ans = min(total_cost(arr, n, mean), total_cost(arr, n, median));
    cout << ans << endl;

    return 0;
}