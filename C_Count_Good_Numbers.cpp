#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int solve_part(int nums)
{
    if (nums == 0)
    {
        return 0;
    }

    int val = nums;

    val -= nums / 2;
    val -= nums / 3;
    val -= nums / 5;
    val -= nums / 7;

    val += nums / 6;
    val += nums / 10;
    val += nums / 14;
    val += nums / 15;
    val += nums / 21;
    val += nums / 35;

    val -= nums / 30;
    val -= nums / 42;
    val -= nums / 70;
    val -= nums / 105;

    val += nums / 210;

    return val;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = solve_part(r) - solve_part(l - 1);

        cout << ans << endl;
    }

    return 0;
}