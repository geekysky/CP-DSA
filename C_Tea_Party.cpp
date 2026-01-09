#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, w;
    cin >> n >> w;

    vector<int> arr(n);
    int t_min = 0;
    map<int, deque<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        mp[arr[i]].push_back(i);
        t_min += (arr[i] + 1) / 2;
    }

    vector<int> cpy = arr;
    sort(arr.begin(), arr.end());

    if (w < t_min)
    {
        cout << -1 << endl;
        return 0;
    }

    // if remaining is there then usko larger vale cup m distribute karo..rather than smaller cups
    // as if ai > aj then ceil(ai/2) > ceil(aj/2) this shouldnt be violated
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = (cpy[i] + 1) / 2;

        w -= (cpy[i] + 1) / 2;
    }
    
    // now...
    while (w > 0)
    {
        int idx = (mp.rbegin()->second).front();
        int diff = min(cpy[idx], res[idx] + w) - res[idx];

        res[idx] = min(cpy[idx], res[idx] + w);

        w = max(0ll, w - diff);
        (mp.rbegin()->second).pop_front();

        if ((mp.rbegin()->second).size() == 0)
        {
            mp.erase(mp.rbegin()->first);
        }
    }

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}