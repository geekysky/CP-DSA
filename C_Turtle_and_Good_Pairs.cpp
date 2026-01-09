#include <bits/stdc++.h>
using namespace std;
#define int long long int

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        string ans = "";

        // 1e5 * 26
        while (ans.size() != n)
        {
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] > 0)
                {
                    ans += ('a' + i);
                    freq[i]--;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}