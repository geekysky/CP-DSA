#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> freq(2e6 + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int i = 0; i <= 2e6; i++)
    {
        if (freq[i] > 1)
        {
            freq[i + 1] += freq[i] / 2;
            freq[i] %= 2;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 2e6 + 1; i++)
    {
        if (freq[i] != 0)
        {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}