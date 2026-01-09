#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> prefix_mex(const vector<int>& a) {
    int n = a.size();
    vector<int> result(n);
    set<int> seen;
    int mex = 0;

    vector<bool> is_present(n + 5, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] < is_present.size()) {
            is_present[a[i]] = true;
        }
        while (is_present[mex]) ++mex;
        result[i] = mex;
    }

    return result;
}


signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n), present(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            present[arr[i]] = 1;
        }

        int mex = n;
        for (int i = 0; i < n; i++)
        {
            if (present[i] == 0)
            {
                mex = i;
                break;
            }
        }

        int len = 0;
        int idx = -1;
        int curr_mex = 0;
        vector<int> pref_mex = prefix_mex(arr);
        for (int i = 0; i < n; i++)
        {
            if (pref_mex[i] == mex)
            {
                // first segment found
                idx = i;
                break;
            }
        }

        // second segment
        vector<int> rem_check;
        for (int i = idx + 1; i < n; i++)
        {
            rem_check.push_back(arr[i]);
        }

        rem_check = prefix_mex(rem_check);

        if (rem_check.size() == 0 or rem_check.back() != mex)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << idx + 1 << endl;
            cout << idx + 2 << " " << n << endl;
        }
    }
    return 0;
}