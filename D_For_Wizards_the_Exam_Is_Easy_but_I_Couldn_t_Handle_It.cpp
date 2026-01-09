#include <bits/stdc++.h>
using namespace std;
#define int long long

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

signed main()
{
    // fast io
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int left = 0, right = 0;
        int diff = 0;

        for (int l = 0; l < n; l++)
        {
            int smaller = 0, greater = 0;
            for (int r = l + 1; r < n; r++)
            {
                if (arr[r] > arr[l])
                {
                    smaller++;
                }
                else if (arr[r] < arr[l])
                {
                    greater++;
                }
                
                int temp = smaller - greater;
                if (temp < diff)
                {
                    diff = temp;
                    left = l;
                    right = r;
                }
            }
        }

        cout << left + 1 << " " << right + 1 << "\n";
    }
    return 0;
}
