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

        string s;
        cin >> s;

        vector<int> values(n), affect(n);
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                values[i] = i;
                affect[i] = (n - i - 1) - i;
            }
            else
            {
                values[i] = (n - i - 1);
                affect[i] = i - (n - i - 1);
            }

            temp += values[i];
        }

        sort(affect.rbegin(), affect.rend());
        for (int i = 0; i < n; i++)
        {
            if (affect[i] > 0)
            {
                // i will change this
                temp += affect[i];
            }
            cout << temp << " ";
        }

        cout << "\n";
    }

    return 0;
}