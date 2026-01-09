#include <iostream>
#include <vector>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> res;
        if (k > (n * (n + 1)) / 2)
        {
            cout << -1 << endl;
            continue;
        }

        else if (k < n - 1)
        {
            res.push_back(2);
            for (int i = 1; i <= k; i++)
            {
                res.push_back(3);
            }
            while ((int)res.size() < n)
            {
                res.push_back(6);
            }
        }

        else
        {
            int low = 0, high = n;
            int ones = 0;

            while (low <= high)
            {
                int mid = (low + high) / 2;
                int p = n * mid - (mid * (mid + 1)) / 2;

                if (p <= k)
                {
                    ones = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            int used = ones * n - (ones * (ones + 1)) / 2;
            int rem = k - used;

            for (int i = 1; i <= ones; i++)
            {
                res.push_back(1);
            }

            res.push_back(2);
            for (int i = 1; i <= rem; i++)
            {
                res.push_back(3);
            }

            while ((int)res.size() < n)
            {
                res.push_back(6);
            }
        }

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
