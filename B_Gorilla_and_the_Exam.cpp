#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        if (k >= n)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<int> frequencies;
        for (auto x : mp)
        {
            frequencies.push_back(x.second);
        }

        sort(frequencies.begin(), frequencies.end());

        int distinct = frequencies.size();
        int idx = 0;

        while (idx < frequencies.size() && k >= frequencies[idx])
        {
            k -= frequencies[idx];
            distinct--;
            idx++;
        }

        cout << distinct << "\n";
    }
    return 0;
}