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
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        int temp = 2;
        if (odd and even)
        {
            cout << 2 << "\n";
        }
        else
        {
            while (true)
            {
                set<int> s;
                for (int i = 0; i < n; i++)
                {
                    s.insert(arr[i] % temp);
                }

                if (s.size() == 2)
                {
                    break;
                }

                temp *= 2;
            }

            cout << temp << "\n";
        }
    }

    return 0;
}