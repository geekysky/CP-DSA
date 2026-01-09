#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> prefix(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (i == 0)
        {
            prefix[i] = arr[i];
        }
        else
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
    }
    if (n == 2)
    {
        if (arr[0] == arr[1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return 0;
    }

    sort(arr.begin(), arr.end());
    if (prefix[n - 1] % 2 == 0 and arr.back() <= prefix[n - 1] - arr.back())
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }

    return 0;
}