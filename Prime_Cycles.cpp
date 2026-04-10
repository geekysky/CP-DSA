#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
vector<int> curr, used;
vector<bool> prime;

void dfs(int level)
{
    if (level == n)
    {
        if (prime[curr[n - 1] + curr[0]])
        {
            ans++;
        }
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        if (!used[i])
        {
            // parity pruning
            if ((i % 2) == (curr[level - 1] % 2))
                continue;

            if (prime[i + curr[level - 1]])
            {
                used[i] = 1;
                curr[level] = i;

                dfs(level + 1);

                used[i] = 0;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n % 2 == 1 && n > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    // Precompute primes up to 2n
    prime.assign(2 * n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 2 * n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 2 * n; j += i)
                prime[j] = false;
        }
    }

    ans = 0;
    curr.assign(n, 0);
    used.assign(n + 1, 0);

    curr[0] = 1;
    used[1] = 1;

    dfs(1);

    cout << ans << endl;
    return 0;
}
