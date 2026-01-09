#include <bits/stdc++.h>
using namespace std;
#define int long long int

int sum_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

signed main()
{
    int n;
    cin >> n;

    int cnt = 0;
    int ans = 1;
    int val = 19;
    while (true)
    {
        if (sum_digits(val) == 10)
        {
            cnt++;
            if (cnt == n)
            {
                ans = val;
                break;
            }
        }
        val++;
    }

    cout << ans << endl;
    return 0;
}