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

        vector<int> arr(n), a_dash(n);
        int l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a_dash[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != a_dash[i])
            {
                l = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] != a_dash[i])
            {
                r = i;
                break;
            }
        }

        multiset<int> ms;
        for (int i = l; i <= r; i++)
        {
            ms.insert(a_dash[i]);
        }

        for (int i = l - 1; i >= 0; i--)
        {
            if (a_dash[i] <= *ms.begin())
            {
                ms.insert(a_dash[i]);
                l--;
            }
            else
            {
                break;
            }
        }

        for (int i = r + 1; i < n; i++)
        {
            if (a_dash[i] >= *ms.rbegin())
            {
                ms.insert(a_dash[i]);
                r++;
            }
            else
            {
                break;
            }
        }

        cout << l+1 << " " << r+1 << endl;
    }
    return 0;
}