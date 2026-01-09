#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define db long double

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> stops(k + 1, 0), times(k + 1, 0);

        for (int i = 1; i <= k; i++)
        {
            cin >> stops[i];
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> times[i];
        }

        while (q--)
        {
            int d;
            cin >> d;

            auto it = lower_bound(stops.begin(), stops.end(), d);
            int next_idx = it - stops.begin();

            if (stops[next_idx] == d)
            {
                cout << times[next_idx] << " ";
                continue;
            }

            int prev_stop = stops[next_idx - 1];
            int prev_time = times[next_idx - 1];
            int next_stop = stops[next_idx];
            int next_time = times[next_idx];

            int time_to_add = (d - prev_stop) * (next_time - prev_time) / (next_stop - prev_stop);

            cout << prev_time + time_to_add << " ";
        }
        cout << endl;
    }
    return 0;
}