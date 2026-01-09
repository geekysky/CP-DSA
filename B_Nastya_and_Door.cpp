#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<pair<int, int>> store;

        int peaks = 0;
        for (int j = 1; j <= (k - 2); j++)
        {
            if (arr[j] > arr[j + 1] and arr[j] > arr[j - 1])
            {
                peaks++;
            }
        }

        store.push_back({peaks, 1});

        for (int i = 1; i <= (n - k); i++)
        {
            if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
            {
                // peak disturbed -> removed
                peaks--;
                peaks = max(0ll, peaks);
            }

            // check if new peak is getting added
            if (arr[i + k - 2] > arr[i + k - 1] and arr[i + k - 2] > arr[i + k - 3])
            {
                peaks++;
            }

            store.push_back({peaks, i + 1});
        }

        // for (auto it : store)
        // {
        //     cout << it.first << " " << it.second << "\n";
        // }

        sort(store.begin(), store.end(), cmp);

        cout << store[0].first + 1 << " " << store[0].second << "\n";
    }

    return 0;
}