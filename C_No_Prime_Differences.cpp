#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int arr[n][m];
        int ctr = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = ctr;
                ctr++;
            }
        }

        if (!is_prime(m))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        // 1nad n/2 and so on...rows reorder
        else
        {
            // m is prime -> also odd
            int stp = n / 2;
            int r_no = 0;
            for (int k = 1; k <= stp; k++)
            {
                for (int i = 0; i < m; i++)
                {
                    cout << arr[r_no + stp][i] << " ";
                }
                cout << endl;
                for (int i = 0; i < m; i++)
                {
                    cout << arr[r_no][i] << " ";
                }
                cout << endl;

                r_no++;
            }

            if (n % 2)
            {
                // print last row
                for (int i = 0; i < m; i++)
                {
                    cout << arr[n - 1][i] << " ";
                }
                cout << endl;
            }
        }

        cout << endl;
    }
    return 0;
}