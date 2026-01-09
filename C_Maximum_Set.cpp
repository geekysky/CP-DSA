#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 998244353;

int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base);
        }
        base = (base * base);
        exp /= 2;
    }
    return result;
}

signed main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        if (r < 2 * l)
        {
            cout << 1 << " " << (r - l) + 1 << endl;
            continue;
        }

        int nums = 0;
        for (int i = l; i <= r; i *= 2)
        {
            nums++;
        }

        int larg_2 = r / (1LL << (nums - 1));

        int one = 0;
        if (larg_2 >= l)
        {
            one = (larg_2 - l + 1);
        }

        int two = 0;
        if (nums > 1)
        {
            int larg_3 = r / ((1LL << (nums - 2)) * 3);

            if (larg_3 >= l)
            {
                int num_starts_for_two = larg_3 - l + 1;
                two = (num_starts_for_two % mod * (nums - 1) % mod) % mod;
            }
        }

        cout << nums << " " << (one + two) % mod << endl;
    }
    return 0;
}