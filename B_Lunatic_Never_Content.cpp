#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
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
        for (int i = 0; i < n / 2; i++)
        {
            ans = __gcd(abs(arr[i] - arr[n - i - 1]), ans);
        }

        cout << ans << "\n";
    }
    return 0;
}