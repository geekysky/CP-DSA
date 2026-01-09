#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << 3 << " " << 1 << " " << 4 << " " << 2 << endl;
    }
    else
    {
        vector<int> arr(n);
        int mid = (n + 1) / 2;
        if (n % 2)
        {
            int idx = 0;
            int val = 1;
            for (int i = 0; i < mid - 1; i++)
            {
                arr[idx] = val;
                arr[idx + 1] = val + mid;

                idx += 2;
                val++;
            }

            arr[n - 1] = mid;
        }
        else
        {
            int idx = 0;
            int val = 1;
            for (int i = 0; i < mid; i++)
            {
                arr[idx] = val;
                arr[idx + 1] = val + mid;

                idx += 2;
                val++;
            }
        }

        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}