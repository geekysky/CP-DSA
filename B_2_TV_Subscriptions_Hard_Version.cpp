#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int min_dist = INT_MAX;
        map<int, int> mp;

        
        for (int j = 0; j < d; j++)
        {
            mp[arr[j]]++;
        }
        
        min_dist = mp.size();
        for (int i = 1; i <= (n - d); i++)
        {
            mp[arr[i + d - 1]]++;

            mp[arr[i - 1]]--;
            if (mp[arr[i - 1]] == 0)
            {
                mp.erase(arr[i - 1]);
            }

            min_dist = min(min_dist, (int)mp.size());
        }

        cout << min_dist << "\n";
    }
    return 0;
}
