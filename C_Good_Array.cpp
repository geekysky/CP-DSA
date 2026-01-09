#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    // sum of all other elements
    if (n == 2)
    {
        cout << 0 << endl;
        cout << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());
    vector<int> ans;
    vector<int> prefix;
    prefix.push_back(0);
    for (int i = 0; i < n; i++)
    {
        prefix.push_back(prefix.back() + arr[i].first);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // if i is the jth index
        int s1 = (i == 0) ? 0 : prefix[i];
        int s2;
        int last;
        if (i == n - 1)
        {
            s1 = prefix[i - 1];
            s2 = 0;
            last = arr[n - 2].first;
        }
        else if (n - 1 - i == 1)
        {
            last = arr[n - 1].first;
            s2 = 0;
        }
        else
        {
            last = arr[n - 1].first;
            s2 = prefix[n - 1] - prefix[i + 1];
        }

        // cout<<s1<<" "<<s2<<" "<<last<<endl;
        if (s1 + s2 == last)
        {
            ans.push_back(arr[i].second);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}