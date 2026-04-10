#include <bits/stdc++.h>
using namespace std;
#define int long long int

int odd_part(int x)
{
    while (x % 2 == 0)
        x /= 2;
    return x;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        bool pos = true;

        for (int i = 1; i <= n; i++)
        {
            if (odd_part(i) != odd_part(arr[i]))
            {
                pos = false;
                break;
            }
        }

        if (pos)
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
