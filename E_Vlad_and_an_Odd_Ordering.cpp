#include <bits/stdc++.h>
using namespace std;
#define int long long int

int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base);
        }
        base = (base * base);
        exp /= 2;
    }
    return result;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        // at each stage ceil(n/2) taken and n/2 left
        int temp = k;
        int left = n;
        int ctr = 0;

        // log n loop
        while (true)
        {
            int val = power(2,ctr);
            int nums = (left + 1) / 2;

            if (temp <= nums)
            {
                // our answer lies in this segment
                // it's val * temp
                cout<<val* (temp*2 - 1)<<endl;
                break;
            }

            ctr++;
            temp-=(left + 1) / 2;
            left=left/2;
        }
    }
    return 0;
}