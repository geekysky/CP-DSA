#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        map<int, int> mp1, mp2;
        map<int, int> indices;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            indices[b[i]] = i;
        }

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            mp1[a[i]] = b[i];
            mp2[b[i]] = a[i];
        }

        int common = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp2[a[i]] != mp1[a[i]])
            {
                common += 100;
                break;
            }
            else if (a[i] == b[i])
            {
                common++;
            }
        }

        if (common > 1)
        {
            cout << -1 << endl;
            continue;
        }

        // for (auto x : indices)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }

        vector<pair<int, int>> ans;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            if (a[i] == b[i] and (i + 1) != (n + 1) / 2)
            {
                // swap to centre
                ans.push_back({i + 1, (n + 1) / 2});
                int val = b[i];
                swap(a[i], a[n / 2]);

                int x = b[i];
                int y = b[n / 2];
                indices[x] = n / 2;
                indices[y] = i;
                swap(b[i], b[n / 2]);
            }

            else
            {
                // p...q
                // q...p
                // cout<<"h1"<<endl;
                int idx = indices[a[i]];
                // n se i places backwards

                if (idx != n - 1 - i)
                {
                    ans.push_back({idx + 1, n - i});
                    int x = b[idx];
                    int y = b[n - 1 - i];
                    indices[x] = n - 1 - i;
                    indices[y] = idx;
                    swap(a[idx], a[n - 1 - i]);
                    swap(b[idx], b[n - 1 - i]);
                }
            }

            // for (auto x : a)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
            // for (auto x : b)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
            // cout << "Indices are :" << endl;
            // for (auto x : indices)
            // {
            //     cout << x.first << " " << x.second << endl;
            // }
        }

        cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x.first << " " << x.second << endl;
        }

        // for (auto x : a)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : b)
        // {
        //     cout << x << " ";
        // }
        // cout << endl
        //      << endl;
    }
    return 0;
}