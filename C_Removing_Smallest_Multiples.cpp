#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool all_ones = true, all_zeros = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                all_ones = false;
            else
                all_zeros = false;
        }

        if (all_ones)
        {
            cout << 0 << "\n";
            continue;
        }
        if (all_zeros)
        {
            cout << n << "\n";
            continue;
        }

        vector<bool> is_present(n + 1, false);
        vector<int> absent;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                is_present[i + 1] = true;
            }
            else
            {
                absent.push_back(i + 1);
            }
        }

        sort(absent.begin(), absent.end());

        vector<bool> processed(n + 1, false);
        int ans = 0;

        for (int pos : absent)
        {
            if (!processed[pos])
            {
                ans += pos;
                processed[pos] = true;

                for (int mul = 2 * pos; mul <= n; mul += pos)
                {
                    if (is_present[mul])
                    {
                        break;
                    }

                    if (!processed[mul] && !is_present[mul])
                    {
                        processed[mul] = true;
                        ans += pos;
                    }
                }
            }
            else
            {
                for (int mul = 2 * pos; mul <= n; mul += pos)
                {
                    if (is_present[mul])
                    {
                        // Found a present position, stop processing multiples
                        break;
                    }

                    if (!processed[mul] && !is_present[mul])
                    {
                        // Mark this multiple as processed and add cost
                        processed[mul] = true;
                        ans += pos; // Add the cost, which is the current position
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}