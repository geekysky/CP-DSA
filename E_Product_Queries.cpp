#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<int> a(n);
    vector<bool> exists(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
            exists[a[i]] = true;
    }

    vector<int> dp(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (exists[i])
        {
            dp[i] = 1;
        }
        else
        {
            int min_factors = LLONG_MAX;
            for (int p = 2; p * p <= i; p++)
            {
                if (i % p == 0)
                {
                    int factor1 = p;
                    int factor2 = i / p;

                    if (dp[factor1] != -1 && dp[factor2] != -1)
                    {
                        min_factors=min(min_factors,(dp[factor1]+dp[factor2]));
                    }
                }
            }

            if(min_factors!= LLONG_MAX){
                dp[i]=min_factors;
            }
        }
    }

    //for(int i=1;)
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}