#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        int low = 0, high = 2 * k;

        // return the largest x such that x*(x-1)<=2*k
        int x = high + 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid * (mid - 1) <= 2 * k)
            {
                x = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        vector<pair<int, int>> coordinates;
        // x pairs of (1,i)
        for (int i = 1; i <= x; i++)
        {
            coordinates.push_back({1, i});
        }

        int rem = k - (x * (x - 1)) / 2;
        int y = 1;
        int one=2;
        while (rem > 0)
        {
            int pairs = (1 + sqrt(1 + 8 * rem)) / 2;
            pairs = max(0ll, pairs - 1);

            for (int i = 0; i < pairs; i++)
            {
                coordinates.push_back({one, y});
                one++;
            }

            rem = max(0ll, rem - ((pairs * (pairs + 1)) / 2));
            y++;
        }
        
        cout<<coordinates.size()<<endl;
        for (auto p : coordinates)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}