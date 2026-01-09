#include <bits/stdc++.h>
using namespace std;
#define int long long int

int power(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int modular_multiply(int a, int b, int mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

const int MAXN = 2e5 + 5;

int n, k;
string s;
int zeroPrefix[MAXN], onePrefix[MAXN], diffPrefix[MAXN];
int sparseTable[20][MAXN], logTable[MAXN];

void sparse()
{
    zeroPrefix[0] = onePrefix[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        zeroPrefix[i] = zeroPrefix[i - 1] + (s[i - 1] == '0');
        onePrefix[i] = onePrefix[i - 1] + (s[i - 1] == '1');
    }

    for (int i = 0; i <= n; i++)
    {
        diffPrefix[i] = zeroPrefix[i] - onePrefix[i];
        sparseTable[0][i] = diffPrefix[i];
    }

    logTable[1] = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        logTable[i] = logTable[i / 2] + 1;
    }

    for (int j = 1; (1 << j) <= n + 1; j++)
    {
        int len = 1 << (j - 1);
        for (int i = 0; i + (1 << j) - 1 <= n; i++)
        {
            sparseTable[j][i] = max(sparseTable[j - 1][i], sparseTable[j - 1][i + len]);
        }
    }
}

int maxi(int left, int right)
{
    int j = logTable[right - left + 1];
    int len = 1 << j;
    return max(sparseTable[j][left], sparseTable[j][right - len + 1]);
}

int value(int left, int right)
{
    int onesMinusZeros = onePrefix[right] - zeroPrefix[left - 1];
    int maxDiffInRange = maxi(left - 1, right);
    return onesMinusZeros + maxDiffInRange;
}

bool possible(int threshold)
{
    int partitions = 0;
    int start = 1;

    while (start <= n && partitions < k)
    {
        int l = start, r = n;
        int bk_pt = -1;

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (value(start, m) >= threshold)
            {
                bk_pt = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        if (bk_pt == -1)
            return false;

        partitions++;
        start = bk_pt + 1;
    }

    return (partitions >= k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;

        sparse();

        int low = 1, high = n;
        int ans = 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
