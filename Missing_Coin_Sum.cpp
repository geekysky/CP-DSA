#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int p_sum = 1;
    int ans = -1;

    if (arr[0] != 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];

        if (curr > p_sum + 1)
        {
            // we found a hole
            ans = p_sum + 1;
            break;
        }

        p_sum += curr;
    }

    if (ans == -1)
    {
        cout << p_sum + 1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}