#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int diff = 0;
        vector<int> ans(n);
        int maxi = LLONG_MAX;
        for (int i = n - 1; i >= 1; i--)
        {
            // y is placed at i...we try appropriate place for x with equal difference
            for (int j = i - 1; j >= 0; j--)
            {
                int temp = (y - x) / (i - j);
                if ((y - x) % (i - j) == 0 and temp > 0)
                {
                    ans[i] = y;
                    bool x_found = false, pos = true;
                    for (int k = i - 1; k >= 0; k--)
                    {
                        ans[k] = ans[k + 1] - temp;
                        if (ans[k] == x)
                        {
                            x_found = true;
                        }
                    }
                    for (int k = i + 1; k < n; k++)
                    {
                        ans[k] = ans[k - 1] + temp;
                    }

                    for (int k = 0; k < n; k++)
                    {
                        if (ans[k] <= 0)
                        {
                            pos = false;
                            break;
                        }
                    }

                    if (x_found and pos)
                    {
                        // minimum valid maximum
                        if(ans[n-1]<maxi)
                        {
                            maxi = ans[n-1];
                            diff = temp;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = 0;
        }
        ans[n - 1] = maxi;
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i + 1] - diff;
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}