#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (k < n - 1)
    {
        int temp = arr[0];
        map<int, int> mp;
        bool found = false;
        int idx = 1;
        int ans = 0;
        while (idx <= n - 1)
        {
            temp = max(temp, arr[idx]);

            mp[temp]++;

            if (mp[temp] >= k)
            {
                ans = temp;
                found = true;
                break;
            }

            idx++;
        }

        if (found == false)
        {
            cout << *max_element(arr.begin(), arr.end()) << "\n";
        }
        else
        {
            cout << temp << "\n";
        }
    }
    else
    {
        cout << *max_element(arr.begin(), arr.end()) << "\n";
    }

    return 0;
}