#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        int balance = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                balance++;
            }
            else
            {
                balance--;
            }

            if (balance == 0)
            {
                ans++;
            }
        }

        if (ans > 1)
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