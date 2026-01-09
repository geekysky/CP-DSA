#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // sqrt n for prime
        int is_prime = true;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            cout << 1 << " " << n - 1 << "\n";
        }
        else
        {
            // find the largest number 'a' whose complementary number 'b' is a multiple of 'a'
            int val = -1;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    val=n/i;
                    break;
                }
            }

            cout << val << " " << n - val << "\n";
        }
    }
    return 0;
}