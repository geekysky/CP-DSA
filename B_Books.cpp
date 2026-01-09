#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool corr_sub_arr(int start, int mid, int k, int arr[], int pref_sum[])
{
    // check if sum from start to mid is <= t
    int sum = -1;

    if (start == 0)
        sum = pref_sum[mid];

    else
    {
        sum = pref_sum[mid] - pref_sum[start - 1];
    }

    return sum <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // let's do a binary search on prefix sum
    int pref_sum[n];
    pref_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        pref_sum[i] = pref_sum[i - 1] + arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // for every i find the j using binary search
        int start = i;
        int end = n - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            // now pass to predicate fn
            if (corr_sub_arr(i, mid, t, arr, pref_sum))
            {
                ans = max(ans, (mid - i + 1));
                start=mid+1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
}