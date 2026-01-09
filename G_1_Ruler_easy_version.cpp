#include <bits/stdc++.h>
using namespace std;
#define ll long long

int query(int a, int b)
{
    int area;
    cout << "? " << a << " " << b << endl;
    cin >> area;

    return area;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int low = 1, high = 1000;
        int ans = high + 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (low == high)
            {
                // could happen in the 11th query
                //  answer is definitely found
                break;
            }

            int area = query(1, mid);
            // cout << low << " " << mid << " " << high <<" "<<area<< endl;

            if (area == mid)
            {
                // look on the right side
                low = mid + 1;
            }
            else
            {
                // mid is a possible answer
                ans = mid;
                high = mid;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}