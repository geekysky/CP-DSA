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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // first 27 numbers m se kisi m na kisi m to non divisble nikalna chahiye
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            bool fnd = false;
            for (int j = 2; j <= min(27ll, i + 2); j++)
            {
                if (arr[i] % j != 0)
                {
                    fnd = true;
                    break;
                }
            }

            if (fnd == false)
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