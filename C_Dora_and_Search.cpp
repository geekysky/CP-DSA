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
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            ms.insert(arr[i]);
        }

        int best_l = -1, best_r = -1;
        int l = 0, r = n - 1;

        while (l < r)
        {
            bool one = true, two = true;

            if (*ms.begin() == arr[l])
            {
                one = false;
            }
            if (*ms.rbegin() == arr[l])
            {
                one = false;
            }
            if (*ms.begin() == arr[r])
            {
                two = false;
            }
            if (*ms.rbegin() == arr[r])
            {
                two = false;
            }

            if (!one && !two)
            {
                ms.erase(ms.find(arr[l]));
                ms.erase(ms.find(arr[r]));
                l++;
                r--;
            }
            else if (one && two)
            {
                best_l = l + 1;
                best_r = r + 1;
                break;
            }
            else if (one)
            {
                ms.erase(ms.find(arr[r]));
                r--;
            }
            else
            {
                ms.erase(ms.find(arr[l]));
                l++;
            }
        }

        if (best_l == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << best_l << " " << best_r << endl;
        }
    }
    return 0;
}