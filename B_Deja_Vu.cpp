#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (auto &it : arr)
            cin >> it;

        int maxi = 32;
        while (q--)
        {
            int x;
            cin >> x;

            if (x >= maxi)
                continue;

            maxi = x;
            for (int i = 0; i < n; i++)
            {
                if ((arr[i] % (1LL << x)) == 0)
                {
                    arr[i] |= (1LL << (x - 1));
                }
            }
        }

        for (auto it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
