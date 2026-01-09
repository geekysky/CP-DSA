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
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            pos[arr[i] - 1] = i;
        }

        vector<int> res;
        if (pos[0] < pos[n - 1])
        {
            // Case: 1 appears before n
            int left = pos[0] - 1;
            multiset<int> ms_lft;
            for (int i = left; i >= 0; i--)
            {
                ms_lft.insert(arr[i]);
            }

            int last_pkd = 1;
            while (left >= 0 && !ms_lft.empty())
            {
                int val;
                if (abs(*ms_lft.begin() - last_pkd) > abs(*ms_lft.rbegin() - last_pkd))
                    val = *ms_lft.begin();
                else
                    val = *ms_lft.rbegin();

                while (left >= 0 && arr[left] != val)
                {
                    ms_lft.erase(ms_lft.find(arr[left]));
                    left--;
                }
                if (left >= 0)
                {
                    res.push_back(arr[left]);
                    last_pkd = arr[left];
                    ms_lft.erase(ms_lft.find(arr[left]));
                    left--;
                }
            }

            reverse(res.begin(), res.end());
            res.push_back(1);
            res.push_back(n);

            int right = pos[n - 1] + 1;
            multiset<int> ms_rt;
            for (int i = right; i < n; i++)
            {
                ms_rt.insert(arr[i]);
            }

            last_pkd = n;
            while (right < n && !ms_rt.empty())
            {
                int val;
                if (abs(*ms_rt.begin() - last_pkd) > abs(*ms_rt.rbegin() - last_pkd))
                    val = *ms_rt.begin();
                else
                    val = *ms_rt.rbegin();

                while (right < n && arr[right] != val)
                {
                    ms_rt.erase(ms_rt.find(arr[right]));
                    right++;
                }
                if (right < n)
                {
                    res.push_back(arr[right]);
                    last_pkd = arr[right];
                    ms_rt.erase(ms_rt.find(arr[right]));
                    right++;
                }
            }

            cout << res.size() << endl;
            for (auto x : res)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            // Case: n appears before 1
            int left = pos[n - 1] - 1;
            multiset<int> ms_lft;
            for (int i = left; i >= 0; i--)
            {
                ms_lft.insert(arr[i]);
            }

            int last_pkd = n;
            while (left >= 0 && !ms_lft.empty())
            {
                int val;
                if (abs(*ms_lft.begin() - last_pkd) > abs(*ms_lft.rbegin() - last_pkd))
                    val = *ms_lft.begin();
                else
                    val = *ms_lft.rbegin();

                while (left >= 0 && arr[left] != val)
                {
                    ms_lft.erase(ms_lft.find(arr[left]));
                    left--;
                }
                if (left >= 0)
                {
                    res.push_back(arr[left]);
                    last_pkd = arr[left];
                    ms_lft.erase(ms_lft.find(arr[left]));
                    left--;
                }
            }
            reverse(res.begin(), res.end());
            res.push_back(n);
            res.push_back(1);

            int right = pos[0] + 1;
            multiset<int> ms_rt;
            for (int i = right; i < n; i++)
            {
                ms_rt.insert(arr[i]);
            }

            last_pkd = 1;
            while (right < n && !ms_rt.empty())
            {
                int val;
                if (abs(*ms_rt.begin() - last_pkd) > abs(*ms_rt.rbegin() - last_pkd))
                    val = *ms_rt.begin();
                else
                    val = *ms_rt.rbegin();

                while (right < n && arr[right] != val)
                {
                    ms_rt.erase(ms_rt.find(arr[right]));
                    right++;
                }
                if (right < n)
                {
                    res.push_back(arr[right]);
                    last_pkd = arr[right];
                    ms_rt.erase(ms_rt.find(arr[right]));
                    right++;
                }
            }

            cout << res.size() << endl;
            for (auto x : res)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
