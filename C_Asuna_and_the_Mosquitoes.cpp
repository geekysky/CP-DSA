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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                even.push_back(arr[i]);
            }
            else
            {
                odd.push_back(arr[i]);
            }
        }
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        if (odd.size() == n or even.size() == n)
        {
            if(odd.size() == n)
            {
                cout << odd.back() << "\n";
            }
            else
            {
                cout << even.back() << "\n";
            }
        }
        else
        {
            cout << sum - odd.size() + 1 << "\n";
        }
    }
    return 0;
}