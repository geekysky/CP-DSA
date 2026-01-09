#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MAXN = 1e7 + 1;

signed main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    vector<int> is_prime(MAXN, 1);
    is_prime[0] = is_prime[1] = 0;
    vector<int> temp;
    for (int i = 2; i * i <= 1e7; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 1e7; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    for(int i = 2; i <= 1e7; i++)
    {
        if(is_prime[i])
        {
            temp.push_back(i);
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] > n)
            {
                break;
            }
            ans += (n / temp[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}