#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int target = 67;
int n;
int sum = 0;

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        n = 0;
        int ele;
        cin >> ele;

        n = ele;

        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            mp[arr[i]] = 1;
        }

        if (mp[67] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}