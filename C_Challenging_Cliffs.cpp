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
        int left = -1, right = -1;
        int minDiff = LLONG_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] < minDiff)
            {
                minDiff = arr[i + 1] - arr[i];
                left = i;
                right = i + 1;
            }
        }

        cout << arr[left] << " ";
        for (int i = right + 1; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i < left; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[right] << endl;
    }
    return 0;
}