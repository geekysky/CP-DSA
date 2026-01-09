#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 200001;

int spf[N];

void sieve()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;

    for (int i = 2; i < N; i++)
    {
        for (int j = 2 * i; j < N; j += i)
        {
            if (spf[j] == j)
                spf[j] = i;
        }
    }
}

int power(int a, int b) {
    if (b == 0)
        return 1;
    int res = power(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    map<int, vector<int>> primes; 
    for (auto x : a)
    {
        while (x != 1)
        {
            int p = spf[x], cnt = 0;
            while (x % p == 0)
                x /= p, cnt++;
            primes[p].push_back(cnt);
        }
    }

    int ans = 1;
    for (auto it : primes)
    {
        int a = it.first;
        sort((it.second).begin(), (it.second).end());

        int len = (it.second).size();
        if (len < n - 1)
        {
            continue;
        }
        else if (len == n - 1)
        {
            ans = ans * power((it.first), (it.second)[0]);
        }
        else if (len == n)
        {
            ans = ans * power((it.first), (it.second)[1]);
        }
    }

    cout << ans << "\n";
    return 0;
}
