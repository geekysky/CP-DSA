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

    multiset<int> ms;
    int towers = 1;
    ms.insert(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int val = arr[i];

        auto it = ms.upper_bound(val);

        if (it == ms.end())
        {
            // new tower has to be introduced
            ms.insert(val);
            towers++;
        }
        else
        {
            // update the existing tower
            ms.erase(ms.find(*it));
            ms.insert(val);
        }
    }

    cout << towers << endl;
    return 0;
}