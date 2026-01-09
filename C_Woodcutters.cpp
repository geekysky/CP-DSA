#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = 2;

    int l = arr[0].first - arr[0].second;
    int r = arr[0].first;

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i].first - arr[i].second > r)
        {
            // this tree can be felled to the left
            ans++;
            l = arr[i].first - arr[i].second;
            r = arr[i].first;
        }
        else if (arr[i].first + arr[i].second < arr[i + 1].first)
        {
            // this tree can be felled to the right
            ans++;
            l = arr[i].first;
            r = arr[i].first + arr[i].second;
        }
        else
        {
            l = arr[i].first;
            r = arr[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}