#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> unsafe(x);
        for (int i = 0; i < x; i++)
        {
            cin >> unsafe[i];
        }

        sort(unsafe.begin(), unsafe.end());
        int longest_safe = 0;
        vector<int> lengths;
        for (int i = 1; i < x; i++)
        {
            longest_safe = max(longest_safe, unsafe[i] - unsafe[i - 1] - 1);
            lengths.push_back(max(0ll, unsafe[i] - unsafe[i - 1] - 1));
        }

        longest_safe = max(longest_safe, n - unsafe[x - 1] + unsafe[0] - 1);
        lengths.push_back(max(0ll, n - unsafe[x - 1] + unsafe[0] - 1));
        if (x == n)
        {
            cout << n << "\n";
            continue;
        }
        if (longest_safe == 1)
        {
            cout << n - 1 << "\n";
            continue;
        }
        else
        {
            sort(lengths.begin(), lengths.end());
            int days = 0;

            for (int i = lengths.size() - 1; i >= 0; i--)
            {
                if (lengths[i] == 0)
                {
                    break;
                }
                else
                {
                    // 2 days to secure this value
                    lengths[i] = max(0ll, lengths[i] - (2 * days));
                    if (lengths[i] == 0 or lengths[i]==1)
                    {
                        for (int j = i - 1; j >= 0; j--)
                        {
                            lengths[j] = 0;
                        }
                        break;
                    }
                    lengths[i]--;
                    days += 2;
                }
            }

            int sum = 0;
            for (int i = 0; i < lengths.size(); i++)
            {
                sum += lengths[i];
            }

            cout << n - sum << "\n";
        }
    }
    return 0;
}