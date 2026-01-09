#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        string asc = s;
        sort(asc.begin(), asc.end());

        string desc = asc;
        reverse(desc.begin(), desc.end());

        int ans = 0;
        if (s == asc)
        {
            cout << 0 << endl;
        }
        else if (s == desc)
        {
            int z = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    z++;
                }
            }

            cout << (n - z + 1) * z << endl;
            continue;
        }
        else
        {
            int l = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    break;
                }
                else
                {
                    l = i;
                }
            }

            // l denotes first 1 from start
            int r = n;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    break;
                }
                else
                {
                    r = i;
                }
            }

            // r denotes last 1 from end 00....l11
            // we need to solve between l and r
            l++;
            r--;
            
            // cout<<l<<" "<<r<<endl;
            if (l < r)
            {
                vector<int> indexes;
                for (int i = l; i <= r; i++)
                {
                    if (s[i] == '1')
                    {
                        indexes.push_back(i);
                    }
                }
                // last one is either unchanged r i.e n or is r+1
                indexes.push_back(r == n ? n : r + 1);

                // for (auto x : indexes)
                // {
                //     cout << x << " ";
                // }
                // cout << endl;

                int one_length = 0;
                for (int i = 0; i < indexes.size() - 1; i++)
                {
                    one_length++;
                    int zeroes_between = indexes[i + 1] - indexes[i] - 1;
                    ans += (one_length + (zeroes_between ? 1 : 0)) * zeroes_between;
                }
            }

            cout << ans << endl;
        }
    }
}
