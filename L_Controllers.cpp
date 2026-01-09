#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool valid_solution_exists(int pos, int neg, int x, int y)
{
    int S = pos - neg;
    if (x == y)
    {
        // Need x*S == 0
        return (x == 0) || (S == 0);
    }
    int D = x - y;
    int N = -(int)y * (int)S; // avoid overflow
    // Check divisibility N % D == 0 using int
    if (D == 0)
        return false; // (covered by x==y above, but safe)
    int q = N / D;
    if (q * D != N)
        return false; // not divisible
    int u = (int)q;
    return (-neg <= u && u <= pos);
}

signed main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            pos++;
        }
        else
        {
            neg++;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (valid_solution_exists(pos, neg, a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}