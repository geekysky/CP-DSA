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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        
        sort(arr.begin(), arr.end());

        vector<int> dup;
        dup.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                dup.push_back(dup.back() + 1);
            }
            else
            {
                dup.push_back(dup.back());
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dup[i] << " ";
        // }
        // cout << endl;

        vector<int> diff(n + 2, 0);

        for (int i = 0; i <= n + 1; i++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), i);
            auto it2 = upper_bound(arr.begin(), arr.end(), i);
            int idx = it - arr.begin();

            int mini = (it2 - arr.begin()) - idx;
            int tot = (arr.end() - it2) + (idx == n ? dup.back() : dup[idx]);

            // cout << mini << " " << tot + mini << endl;
            diff[mini]++;
            if (tot + mini <= n)
                diff[tot + mini + 1]--;

            if (mp[i] == 0)
                break;
        }

        for (int i = 1; i <= n + 1; i++)
        {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i <= n; i++)
        {
            cout << diff[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
