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

        // jo bhi just bada mil raha hai vaha p chale jao
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int lv = arr[k - 1];
        sort(arr.begin(), arr.end());

        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        auto it = lower_bound(arr.begin(), arr.end(), lv);
        ++it;
        if (it == arr.end())
        {
            cout << "YES" << endl;
            continue;
        }
        --it;

        // maximum kaunse tower tak pahuch sakta hu ?
        // is it is the max then yes or else no

        int idx = it - arr.begin();
        int wt = 1;
        bool pos = false;
        while (true)
        {
            if (arr[idx] == arr[n - 1])
            {
                pos = true;
                break;
            }

            // can i gop the next larger one ?
            auto high = upper_bound(arr.begin(), arr.end(), lv);
            int diff = *high - lv;

            int curr = lv - wt + 1;

            if (diff <= curr)
            {
                // possible to go to next tower
                idx = high - arr.begin();
                wt += diff;
                lv = arr[idx];
            }
            else
            {
                pos = false;
                break;
            }
        }

        if (pos)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}