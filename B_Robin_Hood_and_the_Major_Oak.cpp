#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countOdd(ll x)
{
    return (x + 1) / 2; 
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        if (k == 1)
        {
            if (n % 2 == 1)
            {
                cout << "NO" << "\n";
            }
            else
            {
                cout << "YES" << "\n";
            }
        }
        else
        {
            ll start = n - k + 1;

            ll oddCount = countOdd(n) - countOdd(start - 1);

            if (oddCount % 2 == 0)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
