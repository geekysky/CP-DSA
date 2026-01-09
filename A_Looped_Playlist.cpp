#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, p;
    cin >> n >> p;

    vector<int> arr(n);
    int tot_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tot_sum += arr[i];
    }

    int ans = LLONG_MAX;

    // how to find no of iterations it is going to take us
    // can be done in O(n2) -> n <= 1000

    int whole_times = p / tot_sum;
    p %= tot_sum;

    int begin = -1;
    for (int start = 0; start < n; start++)
    {
        // find the ending index
        int end = start;
        int sum = 0;
        int songs = 0;

        while (sum < p)
        {
            sum += arr[end];
            end++;
            end %= n;

            songs++;
        }

        if (songs < ans)
        {
            ans = songs;
            begin = start + 1;
        }
    }

    cout << begin << " " << ans + (whole_times * n) << "\n";

    return 0;
}