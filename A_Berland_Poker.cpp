#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        /* code */
        int n, m, k;
        cin >> n >> m >> k;

        if (n / k >= m)
        {
            cout << m << "\n";
            continue;
        }

        // n/k < m
        int rem_m = m - (n / k);
        int rem_p = k - 1;
        
        int max_jok = (rem_m + (rem_p - 1)) / rem_p;

        cout << n / k - max_jok << "\n";

    }

    return 0;

}    