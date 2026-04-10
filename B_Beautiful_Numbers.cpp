#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        int n = x.length();

        int d1 = x[0] - '0';
        vector<int> rest;

        for (int i = 1; i < n; i++)
        {
            rest.push_back(x[i] - '0');
        }

        sort(rest.begin(), rest.end());

        int kept1 = 1;
        int sum1 = d1;
        for (int d : rest)
        {
            if (sum1 + d <= 9)
            {
                sum1 += d;
                kept1++;
            }
            else
            {
                break;
            }
        }
        int moves1 = n - kept1;

        int kept2 = 0;
        int sum2 = 1;
        for (int d : rest)
        {
            if (sum2 + d <= 9)
            {
                sum2 += d;
                kept2++;
            }
            else
            {
                break;
            }
        }
        int moves2 = n - kept2;

        cout << min(moves1, moves2) << endl;
    }
    return 0;
}