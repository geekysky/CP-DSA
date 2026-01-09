#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(int w, int b, int x)
{
    if (w + b < x)
    {
        return false;
    }

    bool checker = false;
    if (w >= x)
    {
        // place white on largest row
        int rem = w + b - x;

        if (rem < (x * (x - 1)) / 2)
        {
            checker = false;
        }

        else
        {
            checker = true;
        }
    }
    else if (b >= x)
    {
        int rem = w + b - x;

        if (rem < (x * (x - 1)) / 2)
        {
            checker = false;
        }

        else
        {
            checker = true;
        }
    }

    return checker;
}
signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, b;
        cin >> w >> b;

        int low = 0, high = 2e9;

        int ans = high + 1;

        for (int i = 0; i < 150; i++)
        {
            int mid=(low+high)/2;
            // cout<<mid<<"\n"<<possible(w,b,2)<<"\n";

            if (possible(w, b, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}