#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(int mid, int k, string s)
{
    int n = s.size();

    if (mid * k > n)
    {
        return false;
    }

    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    int pairs = 0;
    int singles = 0;

    for (int f : freq)
    {
        pairs += f / 2;
        singles += f % 2;
    }

    if (mid % 2 == 0)
    {
        int pairs_needed = (mid / 2) * k;
        return pairs >= pairs_needed;
    }
    else
    {
        int pairs_needed = ((mid - 1) / 2) * k;
        int singles_needed = k;

        // convert extra pairs to singles
        if (pairs >= pairs_needed)
        {
            singles += (pairs - pairs_needed) * 2;
            return singles >= singles_needed;
        }
        return false;
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

        string s;
        cin >> s;

        int left = 1, right = n;
        int ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (possible(mid, k, s))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}