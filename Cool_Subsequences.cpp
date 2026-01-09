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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int val = -1;
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                val = it.first;
                break;
            }
        }

        if (val != -1)
        {
            cout << 1 << "\n";
            cout << val << "\n";
        }
        else
        {
            // each element occurs only once
            sort(arr.begin(), arr.end());

            bool found = false;
            int x = -1, y = -1;

            for (int i = 1; i < n && !found; i++)
            {
                int sum = arr[0] + arr[i];
                if (sum % 2 == 0)
                {
                    int avg = sum / 2;
                    if (mp[avg] > 0 && avg != arr[0] && avg != arr[i])
                    {
                        found = true;
                        x = arr[0];
                        y = arr[i];
                    }
                }
            }

            if (!found)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    int sum = arr[n - 1] + arr[i];
                    if (sum % 2 == 0)
                    {
                        int avg = sum / 2;
                        if (mp[avg] > 0 && avg != arr[n - 1] && avg != arr[i])
                        {
                            found = true;
                            x = arr[i];
                            y = arr[n - 1];
                        }
                    }
                }
            }

            if (!found)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
                cout << x << " " << y << "\n";
            }
        }
    }
    return 0;
}