#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(vector<int> &arr, int k, int mid)
{
    // can the maximum element be >= mid ?
    // pf : TTTTFFFFF

    int req = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= mid)
        {
            return true;
        }
    }

    int mini_req = LLONG_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        // can the ith index be >= mid
        int temp = mid - arr[i];
        bool pos = true;

        // consecutive indices should be >= mid-j
        for (int j = i + 1; j < arr.size(); j++)
        {

            if (arr[j] < mid - (j - i) and j == arr.size() - 1)
            {
                pos = false;
                break;
            }
            else if (arr[j] < mid - (j - i))
            {
                temp += mid - (j - i) - arr[j];
            }
            else
            {
                // good value
                break;
            }
        }

        // cout << "mid is:" << mid << endl;
        // cout << "for ith index pos and temp are:" << pos << " " << temp << endl;
        if (pos and temp <= k)
        {
            // cout << "possible" << endl;
            return true;
        }
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // at max n-1 good indices
        int low = *max_element(arr.begin(), arr.end());
        int high = low + k;

        int ans = high + 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(arr, k, mid))
            {
                // cout << mid << endl;
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // cout << possible(arr, k, 4) << endl;

        cout << ans << endl;
    }
    return 0;
}