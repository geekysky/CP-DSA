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
        map<int, int> mp;
        mp[0] = 3;
        mp[1] = 1;
        mp[2] = 2;
        mp[3] = 1;
        mp[5] = 1;

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        map<int, int> mp1;
        for (int i = 0; i < n; i++)
        {
            mp1[arr[i]]++;

            if (mp1[0] >= 3 and mp1[1] >= 1 and mp1[2] >= 2 and mp1[3] >= 1 and mp1[5] >= 1)
            {
                cout << i + 1 << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << 0 << "\n";
    }
    return 0;
}