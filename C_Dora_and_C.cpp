#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int g = __gcd(a, b);
        for (int i = 0; i < n; i++)
        {
            arr[i] %= g;
        }

        sort(arr.begin(), arr.end());
        int mini=arr[n-1]-arr[0];

        for(int i=1;i<n;i++){
            mini=min(mini,abs(arr[i]-(arr[i-1]+g)));
        }

        cout<<mini<<endl;

    }

    return 0;
}
