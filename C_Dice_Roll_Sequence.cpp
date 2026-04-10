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

        int ans = 0;
        int cont = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1] or arr[i] + arr[i + 1] == 7)
            {
                cont++;
            }
            else
            {
                // break ho gaya
                ans += (cont + 1) / 2;
                cont = 0;
            }
        }

        ans += (cont + 1) / 2;

        cout << ans << endl;
    }
    return 0;
}