#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s;
    cin >> t;

    vector<int> arr(26, 0);
    for (int i = 0; i < m; i++)
    {
        arr[t[i] - 'a']++;
    }

    int left = 0, ans = 0;
    for (int right = 0; right < n; right++)
    {
        arr[s[right] - 'a']--;

        while (arr[s[right] - 'a'] < 0)
        {
            // place cards as we have picked up cards which we don't have
            arr[s[left] - 'a']++;
            left++;
        }

        ans += (right - left + 1);
    }

    cout << ans << "\n";

    return 0;
}