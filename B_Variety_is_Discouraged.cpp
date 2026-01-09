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
        map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        set<int> unique;
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            if (it->second == 1)
            {
                unique.insert(it->first);
            }
        }

        int maxi = 0, leftest = -1, rightest = -1;
        int l = 0;

        for (int r = 0; r < n; r++)
        {
            if (unique.count(arr[r]) == 0)
            {
                l = r + 1;
            }
            else
            {
                int length = r - l + 1;
                if (length > maxi)
                {
                    maxi = length;
                    leftest = l;
                    rightest = r;
                }
            }
        }

        if (maxi == 0)
        {
            cout << "0" << "\n";
        }
        else
        {
            cout << leftest + 1 << " " << rightest + 1 << "\n";
        }
    }

    return 0;
}
