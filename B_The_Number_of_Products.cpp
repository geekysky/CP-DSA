#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] < 0)
        {
            neg++;
        }
    }

    if (neg == 0)
    {
        cout << 0 << " " << n * (n + 1) / 2 << endl;
        return 0;
    }

    vector<pair<int, int>> reach(neg);
    int val = 0;
    neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg++;
            if (neg == 1)
            {
                // only it's left;
                reach[neg - 1].first = val;
            }
            else
            {
                // current left
                reach[neg - 1].first = val;

                // previous right
                reach[neg - 2].second = val;
            }

            val = 0;
        }
        else
        {
            val++;
        }
    }

    // last negative number's right needs to be defined
    reach[reach.size() - 1].second = val;

    int odd_left = 0, even_left = 0;
    neg = 0;
    int ans = 0;

    // for(auto x:reach){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg++;
            int self = reach[neg - 1].second * (reach[neg - 1].first + 1);
            self += (reach[neg - 1].first + 1);
            // cout << self << endl;
            ans += self;
            if (neg % 2)
            {
                ans += odd_left;
                // cout << odd_left << endl;
                // cout << endl;
                odd_left += (reach[neg - 1].first + 1);
            }
            else
            {
                ans += even_left;
                // cout << even_left << endl;
                // cout << endl;
                even_left += (reach[neg - 1].first + 1);
            }
        }
    }

    cout << ans << " " << (n * (n + 1)) / 2 - ans << endl;

    return 0;
}