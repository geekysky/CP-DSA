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

        vector<int> arr(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int pairs = 0;

        int sum = 0;
        vector<int> ans;
        int s = 0, e = 2 * n - 1;

        if (n == 1 and (arr[1] == 2 * arr[0]))
        {
            cout << arr[0] << " " << 3 * arr[0] << " " << arr[1] << endl;
            continue;
        }

        int odd = 0, even = 0;
        for (int i = 0; i < 2 * n; i += 2)
        {
            odd += arr[i];
            even += arr[i + 1];
        }

        ans.push_back(even - odd);
        for (int i = 0; i < 2 * n; i += 2)
        {
            ans.push_back(arr[i + 1]);
            ans.push_back(arr[i]);
        }

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}