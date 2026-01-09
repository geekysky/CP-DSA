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
        vector<int> idx(n+1), val(n+1);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            idx[i + 1] = arr[i];
            val[arr[i]] = i + 1;
        }

        vector<int> correct(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (idx[i + 1] == i + 1)
            {
                correct[i] = 0;
                continue;
            }

            if (correct[i] == -1)
            {
                int x = idx[i + 1];
                int y = i + 1;

                int check = idx[x];
                if (y == check)
                {
                    // no swapping needed
                    // x...y
                    // y...x

                    correct[i] = 0;
                    correct[x - 1] = 0;
                }
                else
                {
                    // swapping needed
                    int index = val[i + 1];

                    // swap between index and x

                    idx[x] = y;
                    idx[index] = check;

                    val[y] = x;
                    val[check] = index;

                    ans++;
                    correct[i] = 0;
                    correct[x - 1] = 0;
                }
                // cout << "Current Index is :" << i + 1 << endl;
                // cout << "Index map :" << endl;
                // for (auto x : idx)
                // {
                //     cout << x.first << " " << x.second << endl;
                // }
                // cout << "Value map :" << endl;
                // for (auto x : val)
                // {
                //     cout << x.first << " " << x.second << endl;
                // }

                // cout << "Taken array is :" << endl;
                // for (auto x : correct)
                // {
                //     cout << x << " ";
                // }
                // cout << endl;
                // cout << "Answer is " << ans << endl;
            }
        }

        cout << ans << endl;
    }
    return 0;
}