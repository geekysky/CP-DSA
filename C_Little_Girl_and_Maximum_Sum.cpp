#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n), freq(n), temp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        temp[l]++;
        if (r < n - 1)
            temp[r + 1]--;
    }

    freq[0] = temp[0];
    for (int i = 1; i < n; i++)
    {
        freq[i] = freq[i - 1] + temp[i];
    }

    sort(arr.rbegin(), arr.rend());
    sort(freq.rbegin(), freq.rend());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i] * freq[i];
    }

    cout << ans << "\n";

    return 0;
}
