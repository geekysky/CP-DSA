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

        sort(arr.begin(), arr.end());
        int groups = 0;
        int mem = 0;

        int temp = 0;
        int idx = 0;

        while (arr[idx] == 1)
        {
            groups++;

            idx++;
        }

        while (idx < n)
        {
            mem++;

            if (mem == arr[idx])
            {
                // create a new group
                groups++;
                mem = 0;
            }

            idx++;
        }

        cout << groups << "\n";
    }
    return 0;
}