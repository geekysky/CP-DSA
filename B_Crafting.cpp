#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int deficit = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                deficit++;
            }
        }

        if (deficit == 0)
        {
            cout << "YES" << "\n";
        }
        else if (deficit > 1)
        {
            cout << "NO" << "\n";
        }
        else
        {
            // only one deficit
            bool possible = true;
            int diff = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < b[i])
                {
                    diff = b[i] - a[i];
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (a[i] >= b[i])
                {
                    if (abs(a[i] - b[i]) < diff)
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible)
            {
                cout << "NO" << "\n";
            }
            else
            {
                cout << "YES" << "\n";
            }
        }
    }
    return 0;
}