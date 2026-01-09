#include <bits/stdc++.h>
using namespace std;
#define int long long int

int calculate(int k, int mid)
{
    if (mid > k)
    {
        int sum = k * (k + 1);
        sum /= 2;

        int total = 2 * k - 1;
        int extra = total - mid;

        int temp = k * (k - 1);
        temp -= (extra * (extra + 1));
        temp /= 2;

        return sum + temp;
    }
    else
    {
        int sum = mid * (mid + 1);
        sum /= 2;

        return sum;
    }
}

bool possible(int k, int x, int mid)
{
    if (mid > k)
    {
        int sum = k * (k + 1);
        sum /= 2;

        int total = 2 * k - 1;
        int extra = total - mid;

        int temp = k * (k - 1);
        temp -= (extra * (extra + 1));
        temp /= 2;

        return (sum + temp) <= x;

        return sum <= x;
    }
    else
    {
        int sum = mid * (mid + 1);
        sum /= 2;

        return sum <= x;
    }
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k, x;
        cin >> k >> x;

        int low = 1, high = 2 * k - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(k, x, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(calculate(k,ans)==x){
            cout<<ans<<"\n";
        }
        else{
            ans=min(ans+1,2*k-1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}