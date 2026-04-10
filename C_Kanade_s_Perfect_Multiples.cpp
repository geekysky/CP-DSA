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
        map<int, int> marked;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            marked[arr[i]] = -1;
        }

        sort(arr.begin(), arr.end());
        bool ans = true;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (marked[arr[i]] == -1)
            {
                int val = arr[i];
                for (int j = val; j <= k; j += val)
                {
                    if (marked.count(j) == 0)
                    {
                        // not present in the array a
                        ans = false;
                        break;
                    }
                    else if (marked[j] == -1)
                    {
                        marked[j] = 1;
                    }
                }

                if (!ans)
                {
                    break;
                }

                // all multiples <= k present for this val
                res.push_back(val);
            }
        }

        if (!ans)
        {
            cout << -1 << endl;
            continue;
        }

        cout << res.size() << endl;
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}