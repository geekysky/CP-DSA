#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int y, x;
        cin >> x >> y;

        // xth row and yth column now...

        int layer = max(x, y);
        // now the coordinate belongs to (layer,layer) L
        int value = layer * layer - (layer - 1);

        if (layer % 2)
        {
            // the diagonal coordinate value is odd
            // towards left - decreasing
            // towards up - increasing

            if (x == layer)
            {
                // same row
                int diff = layer - y;
                cout << value - diff << "\n";
            }
            else
            {
                // same column
                int diff = abs(layer - x);
                cout << value + diff << "\n";
            }
        }
        else
        {
            // the diagonal value is even
            // towards left - increasing
            // towards up - decreasing

            if (x == layer)
            {
                // same row
                int diff = layer - y;
                cout << value + diff << "\n";
            }
            else
            {
                // same column
                int diff = abs(layer - x);
                cout << value - diff << "\n";
            }
        }
    }
    return 0;
}