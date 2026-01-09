#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(int mid, vector<int> &arr, int x, int a, int y, int b, int k)
{
    // check karo ki pehle mid elements m k achieve ho raha hai kya
    int lcm = (a * b) / __gcd(a, b);
    int type_x = mid / a;
    int type_y = mid / b;
    int both = mid / lcm;

    int contribution = 0;
    for (int i = 1; i <= mid; i++)
    {
        if (i % lcm == 0)
        {
            type_x--;
            type_y--;
        }
    }

    int ptr = 0;
    for (int i = 0; i < both; i++)
    {
        // largest uthao for x_y type
        int temp = ((x + y) * arr[ptr]) / 100;
        contribution += temp;

        ptr++;
    }

    if (contribution >= k)
    {
        return true;
    }

    if (y > x)
    {
        // first assign the larger ones to y type
        int temp = 0;
        for (int i = 0; i < type_y; i++)
        {
            temp += (y * arr[ptr]) / 100;
            ptr++;
        }
        contribution += temp;

        if (contribution >= k)
        {
            return true;
        }

        temp = 0;
        // add remaining x type
        for (int i = 0; i < type_x; i++)
        {
            temp += (x * arr[ptr]) / 100;
            ptr++;
        }
        contribution += temp;

        if (contribution >= k)
        {
            return true;
        }
    }
    else
    {
        // either x>y or x==y
        // let's assign x first then y...wouldn't matter if x==y
        int temp = 0;
        for (int i = 0; i < type_x; i++)
        {
            temp += (x * arr[ptr]) / 100;
            ptr++;
        }
        contribution += temp;

        if (contribution >= k)
        {
            return true;
        }

        temp = 0;
        // add remaining y type
        for (int i = 0; i < type_y; i++)
        {
            temp += (y * arr[ptr]) / 100;
            ptr++;
        }
        contribution += temp;

        if (contribution >= k)
        {
            return true;
        }
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x, y, a, b, k;
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;

        int low = 1, high = n;
        int up=INT_MAX;
        int ans = -1;

        sort(arr.rbegin(), arr.rend());

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(mid, arr, x, a, y, b, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}