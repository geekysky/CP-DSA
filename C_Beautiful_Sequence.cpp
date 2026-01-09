#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // Compute prefix array for 2's count
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (arr[i] == 2);
        }

        vector<int> ones, threes;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                ones.push_back(i);
            else if (arr[i] == 3)
                threes.push_back(i);
        }

        int max_prefix = prefix[n];
        vector<ll> pow2(max_prefix + 1, 1), inv_pow2(max_prefix + 1, 1);
        ll inv_2 = 500000004; // pow(2, MOD-2, MOD) = 2^(MOD-2) % MOD

        for (int i = 1; i <= max_prefix; i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
            inv_pow2[i] = (inv_pow2[i - 1] * inv_2) % MOD;
        }

        vector<ll> threes_pow, cum_threes_pow(1, 0);
        for (int b : threes)
        {
            threes_pow.push_back(pow2[prefix[b]]);
            cum_threes_pow.push_back((cum_threes_pow.back() + threes_pow.back()) % MOD);
        }

        ll total_sum_part1 = 0, total_pairs = 0;
        for (int a : ones)
        {
            int j = upper_bound(threes.begin(), threes.end(), a) - threes.begin();
            ll sum_pow = (cum_threes_pow.back() - cum_threes_pow[j] + MOD) % MOD;
            ll contribution = (sum_pow * inv_pow2[prefix[a + 1]]) % MOD;
            total_sum_part1 = (total_sum_part1 + contribution) % MOD;
            total_pairs = (total_pairs + (int)threes.size() - j) % MOD;
        }

        ll answer = (total_sum_part1 - total_pairs + MOD) % MOD;
        cout << answer << "\n";
    }

    return 0;
}