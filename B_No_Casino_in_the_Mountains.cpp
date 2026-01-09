#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int cont = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                ans += (cont) / (k + 1);

                if (cont % (k + 1) == k)
                {
                    ans++;
                }

                cont=0;
            }
            else
            {
                cont++;
            }
        }
        ans += (cont) / (k + 1);

        if (cont % (k + 1) == k)
        {
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}